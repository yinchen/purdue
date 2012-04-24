/*

CORRECT OUTPUT

----------------

@:T1

@:S

@:R

@:T1

@:S

@:T3 

@:M fa.

       @:S

@:S

@:S

@:M fb.

       @:S

@:M fc.

       @:T3 

@:M fd.

       @:T4 

@:S

@:T4

@:S

@:KS fb

@:T5

@:S

@:S

@:S

@:T5



IF YOU FEEL YOUR SOLUTION IS CORRECT BUT DIFFERS FROM ABOVE, PLEASE CONTACT THE TAs.



*/



#include <xinu.h>

#include <stdio.h>







char *procname(pid32 pid){

  return proctab[pid].prname;

}



char *currprocname(void){

  return procname(currpid);

}

/* 

 * functions to encode/decode a pid and a message number in a word

 * 16 most significant bits: pid

 * 16 least significant bits: message number

 */

int32 gen_msg(pid32 pid, umsg32 msg_nb){

  return (((unsigned int)pid << 16) | ((unsigned int) msg_nb));

}



int msg_to_pid(umsg32 msg){

  return ((unsigned int)msg >>16);

}



int msg_to_nb(umsg32 msg){

  return ((unsigned int)msg & 0XFFFF);

}





/*

 * functions to validate the stress tests

 * assumptions: n senders and m messages per sender 

 */



/*

 * permissive definition of fairness:

 *   within 3*n*m received messages, there should be at least

 *   one message from each process

 *

 * method assumption: rcvd is an array of int32 messages of size nb_proc*nb_msg

 * returns 1 if this definition of fairness is satisfied; 0 otherwise

 */

int locking_is_fair(umsg32 *rcvd, int nb_proc, uint32 nb_msg){

  char rcvd_from[NPROC];

  int nb_senders, i;



  for(i=0; i<NPROC; i++)

    rcvd_from[i] = 0;



  for(i=0; i < nb_proc*3 ; i++)

    rcvd_from[msg_to_pid(rcvd[i])] = 1;



  nb_senders = 0;

  for(i=0; i<NPROC; i++)

    if(rcvd_from[i])

      nb_senders++;



  return (nb_senders == nb_proc);

}





int x_sendb(pid32 pid, umsg32 msg){

  int ret=SYSERR;

  ret = sendb(pid, msg);

  kprintf("S\r\n");

  if(ret == SYSERR) kprintf("%s:%s: Could not send message 0x%X to proc %d\r\n",

			    currprocname(), __FUNCTION__, msg, pid);

  return ret;

}





int x_sendb_(pid32 pid, umsg32 msg){

  int ret=SYSERR;

  ret = sendb(pid, msg);  

  if(ret == SYSERR) kprintf("%s:%s: Could not send message 0x%X to proc %d\r\n",

			    currprocname(), __FUNCTION__, msg, pid);

  return ret;

}



int32 x_receive_expect(umsg32 expected){

  umsg32 msg;

  kprintf("R\r\n");

  msg = receiveb();

  if( msg != expected)

    kprintf("%s(%d): ERROR received 0X%0X instead of 0X%0X\n", currprocname(), currpid, msg, expected);

  return msg;

}



////////////////////////// UTILITY PROCESSES //////////////////////////////





/* 

 * blocking send of message msg to process of pid "pid" then exits

 */

void proc_sendb(pid32 pid, umsg32 msg){

  /*

  kprintf("%s(%d): about to send 0x%0X to %s(%d)\n",

	  currprocname(), currpid, msg,

	  procname(pid), pid);

	  */

  x_sendb(pid, msg);

  /*

  kprintf("%s(%d): Done sending 0x%0X to %s(%d)\n",

	  currprocname(), currpid, msg,

	  procname(pid), pid);

	  */

}





/* 

 * blocking send of "m" messages to process of pid "pid" 

 * and encodes its own sender number ("snum") in them

 * 

 */

void proc_sendb_many(pid32 pid, int snum, int m){

  int i;

  

  for(i=0; i<m; i++)

    x_sendb_(pid, gen_msg(snum, i));  

  

}





/*

 * expects to receive a specific message

 * silent if satified; complains otherwise

 */  

void proc_receive_expect(umsg32 expected){

  umsg32 msg;

  sleep(2);

  msg = x_receive_expect(expected);

}





/*

 * receives "how_many" many messages and stores them in order

 * into the recv_buf array which is allocated externally to this

 * process (allows for analysis by another process)

 */

void proc_receive_many(int how_many, umsg32 *recv_buf){

  int i;



  sleep(3);

  

  for(i=0; i<how_many; i++){

    recv_buf[i] = receiveb();

  }

  

  kprintf("ST %d. \r\n", how_many);

  // should hav received 25 messages. Total points 20.

  

}



//////////////////////////    TEST CASES    //////////////////////////////





void test_snd_block(void)

{

  pid32 pid_snd, pid_rcv;

  umsg32 msg = 0XFA;



  kprintf("T1\r\n");

  

  pid_rcv = create((int *)proc_receive_expect, 2000, 25, "receiver proc", 1, msg);

  pid_snd = create((int *)proc_sendb, 2000, 20, "bsender proc", 2, pid_rcv, msg );

  resume(pid_rcv);

  x_sendb(pid_rcv, msg);

  resume(pid_snd);

  sleep(2);

  kprintf("T1\r\n");

  

  // Test Single Proc Block END. -20 if Receiver msg is not between two sender's message

}



#define STRESS_SENDB_NBPROC 5



#define STRESS_SENDB_NBMSG 5



#define STRESS_SENDB_NBMSG_TOTAL STRESS_SENDB_NBPROC*STRESS_SENDB_NBMSG



umsg32 msg_buf[STRESS_SENDB_NBPROC][STRESS_SENDB_NBMSG];



void test_stess(void)

{

  pid32 pids_snd[STRESS_SENDB_NBPROC], pid_rcv;

  int i;

  char procname[15];



  kprintf("T2\r\n");



  sprintf(procname, "rcvmany(%5d)", STRESS_SENDB_NBMSG_TOTAL);

  pid_rcv = create((int *)proc_receive_many, 2000, 20, procname, 2 , STRESS_SENDB_NBMSG_TOTAL, msg_buf);

  if(pid_rcv == SYSERR) kprintf("%s: ERROR creating receiver\n", __FUNCTION__);

  resume(pid_rcv);

  

  for(i=0; i<STRESS_SENDB_NBPROC; i++){



    sprintf(procname, "bsender #%2d", i);

    pids_snd[i] = create((int *)proc_sendb_many, 2000, 20, procname, 

			 3, pid_rcv, i, STRESS_SENDB_NBMSG );

    if(pids_snd[i] == SYSERR) kprintf("%s: ERROR creating bsender #%2d\n", __FUNCTION__, i);

    resume(pids_snd[i]);

  }  

  // sleep 

  sleep(5);   

  kprintf("T2\r\n");

}



void recv_four(void){  

  umsg32 msg;

  //kprintf("Block and Recv Fifo. Total points 20\n");

  

  msg = receiveb();

  kprintf("M %x.\n",msg);

  sleep(1);

  msg = receiveb();

  kprintf("M %x.\n",msg);

  sleep(1);

  msg = receiveb();

  kprintf("M %x.\n",msg);

  sleep(1);

  msg = receiveb();

  kprintf("M %x.\n",msg);  

  

}



void test_fifo(void)

{

  pid32 pid_snd1, pid_snd2,pid_snd3,pid_rcv;

  umsg32 msg1 = 0XFA;

  umsg32 msg2 = 0XFB;

  umsg32 msg3 = 0XFC;

  umsg32 msg4 = 0XFD;



  kprintf("T3 \r\n");

  

  pid_rcv = create(recv_four, 2000, 20, "rcv_four", 0);

  pid_snd1 = create((int *)proc_sendb, 2000, 20, "sender proc1", 2, pid_rcv, msg2 );

  pid_snd2 = create((int *)proc_sendb, 2000, 20, "sender proc2", 2, pid_rcv, msg3 );

  pid_snd3 = create((int *)proc_sendb, 2000, 20, "sender proc2", 2, pid_rcv, msg4 );

  if(pid_rcv == SYSERR || pid_snd1 == SYSERR || pid_snd2 == SYSERR || pid_snd3 == SYSERR){

          kprintf("Test 8 failed, could not create processes \r\n");

  }

  

  resume(pid_rcv);

  x_sendb(pid_rcv, msg1);

  resume(pid_snd1);

  resume(pid_snd2);

  resume(pid_snd3);

  sleep(3);

  kprintf("T3 \r\n");

  

}





void recv_while(void){

  while(1);

}



void recv_two(void){

  

  umsg32 msg1, msg2;  

  sleep(3);

  msg1 = receiveb();

  msg2 = receiveb();

  kprintf("KS %x\r\n",msg2);

  

  //kprintf("!!!! test_kill_sendr: Msg should be 0xFB. It is %x. If not -20\r\n",msg2);

  

}



void test_kill_sendr(void)

{

  pid32 pid_snd1, pid_snd2,pid_rcv;

  umsg32 msg1 = 0XFA,msg2 = 0XFB;  



  kprintf("T4 \r\n");

  

  pid_rcv = create(recv_two, 2000, 20, "rcv_while", 0);

  pid_snd1 = create((int *)proc_sendb, 2000, 20, "sender proc1", 2, pid_rcv, msg1 );

  pid_snd2 = create((int *)proc_sendb, 2000, 20, "sender proc2", 2, pid_rcv, msg2 );

  if(pid_rcv == SYSERR || pid_snd1 == SYSERR || pid_snd2 == SYSERR){

          kprintf("Test 8 failed, could not create processes \r\n");

  } 

  

  resume(pid_rcv);

  x_sendb(pid_rcv, msg1);

  resume(pid_snd1);

  resume(pid_snd2);  

  sleepms(100);

  kill(pid_snd1);

  sleepms(2000);

  kprintf("T4\r\n");

}



void test_kill_recvr(void)

{

  pid32 pid_snd1, pid_snd2,pid_rcv;

  umsg32 msg = 0XFA;

  kprintf("T5\r\n");



  pid_rcv = create(recv_while, 2000, 20, "rcv_while", 0);

  pid_snd1 = create((int *)proc_sendb, 2000, 20, "sender proc1", 2, pid_rcv, msg );

  pid_snd2 = create((int *)proc_sendb, 2000, 20, "sender proc2", 2, pid_rcv, msg );

  if(pid_rcv == SYSERR || pid_snd1 == SYSERR || pid_snd2 == SYSERR){

          kprintf("Test 8 failed, could not create processes \r\n");

  }

  

  

  resume(pid_rcv);

  x_sendb(pid_rcv, msg);

  resume(pid_snd1);

  resume(pid_snd2);  

  sleepms(1000);

  kill(pid_rcv);

  sleepms(2000);

  kprintf("T5\r\n");

  //kprintf("!!!!!!! TEST Receiver kill when senders block END. OS should exit normally. If not -20\r\n");

}





int main(void)

{

    //test_snd_block();

    //sleep(5);

    //test_fifo();

    //sleep(5);

    //test_stess();

    //sleep(5);

    //test_kill_sendr();

    //sleep(7);

    test_kill_recvr();

    sleep(5);    

    return 0;  

}

