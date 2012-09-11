using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using TFTPClientNameSpace;
using System.IO;

namespace SpecExplorer1
{
    public class TFTPclientAdaptor
    {
        #region Declarations

        /// <summary>
        /// The current states of the TFTP client implementation. 
        /// </summary>
        public FSM_Modes tftpClientMode;
        
        /// <summary>
        /// The 9 states of the TFTP client implementation. They define the state space of the finite state machine mode of the TFTP client.
        /// </summary>
        public enum FSM_Modes
        {
            INIT = 0,
            EXIT = 1,
            ERROR = 2,
            RRQ_SENT = 3,
            DATA_RECEIVED = 4,
            ACK_SENT = 5,
            WRQ_SENT = 6,
            ACK_RECEIVED = 7,
            DATA_SENT = 8,
        }

        /// <summary>
        /// Three different modes in transfering files. This type is one of the parameters of Get, sendReadRequest, Put, sendWriteRequest.
        /// </summary>
        public enum Modes
        {
            NetAscii = 0,
            Octet = 1,
            Mail = 2,
        }

        /// <summary>
        /// The operation codes used for assemblying packets.
        /// </summary>
        public enum Opcodes
        {
            Read = 0,
            Write = 1,
            Data = 2,
            Ack = 3,
            Error = 4,
        }

        #endregion

        #region Methods

        /// <summary>
        /// Initialze the TFTP client. Set the state to be INIT
        /// </summary>
        public static void initialize()
        {
        }

        /// <summary>
        /// Send Read Request. It creates the TFTP read request packet, send the packet. INIT --> RRQ_SENT.
        /// </summary>
        /// <param name="remoteFile">The remote file.</param>
        /// <param name="localFile">The local file.</param>
        /// <param name="tftpMode">The TFTP mode, NetAscii, Octet, Mail.</param>
        public static void sendReadRequest()
        {
        }

        /// <summary>
        /// Receive Data Block from the TFTP server. RRQ_SENT or ACK_SENT --> DATA_RECEIVED.
        /// </summary>
        /// <param name="rcvBuffer">the receiving buffer for return.</param>
        /// <returns>
        /// A int variable that tell the length of the receiving buffer. 
        /// </returns>
        public static int receiveDataBlock()
        {
            return -1;
        }

        /// <summary>
        /// Send ACK packet to the TFTP server, after successfully receive the data block from the TFTP server. DATA_RECEIVED --> ACK_SENT.
        /// </summary>
        public static void sendACK()
        {
        }

        /// <summary>
        /// check whether it is time to successfully exit. If yes, current state --> EXIT; otherwise, keep the current state.
        /// </summary>
        /// <param name="len">The length of receving buffer.</param>
        /// <returns>
        /// A bool variable indicating whether it is time to successfully exit. It is TRUE for successfully exit, FALSE for staying in the loop and continuing the file transfer. 
        /// </returns>
        public static bool canGetExit()
        {
            return false;
        }

        /// <summary>
        /// Send Write Request. Create the WRQ packet, send it to the server. INIT --> WRQ_SENT.
        /// </summary>
        /// <param name="remoteFile">The remote file.</param>
        /// <param name="localFile">The local file.</param>
        /// <param name="tftpMode">The TFTP mode.</param>
        /// <param name="sndBuffer">The returned sending buffer.</param>
        public static void sendWriteRequest()
        {
        }

        /// <summary>
        /// Send Data Block. ACK_RECEIVED --> DATA_SENT.
        /// </summary>
        /// <param name="fileStream">The file stream for writting the downloading file.</param>
        /// <param name="sndBuffer">The returned sending buffer.</param>
        public static void sendDataBlock()
        {
            // initialize FTP client
            TFTPClient client = new TFTPClient("127.0.0.1");

            string localFile = "sample.txt";
            BinaryReader fileStream = new BinaryReader(new FileStream(localFile, FileMode.Open, FileAccess.Read, FileShare.ReadWrite));

            byte[] sndBuffer;
            client.sendDataBlock(fileStream, out sndBuffer);
        }

        /// <summary>
        /// Receive ACK from the server. WRQ_SENT or DATA_SENT --> ACK_RECEIVED
        /// </summary>
        /// <param name="rcvBuffer">The receiving buffer.</param>
        /// <returns>
        /// A int variable that tell the length of the receiving buffer. 
        /// </returns>
        public static int receiveACK()
        {
            return -1;
        }

        /// <summary>
        /// check whether it is time to successfully exit. If yes, current state --> EXIT; otherwise, keep the current state unchanged. 
        /// </summary>
        /// <param name="len">The length of the sending buffer.</param>
        /// <returns>
        /// A bool variable indicating whether it is time to successfully exit. It is TRUE for successfully exit, FALSE for staying in the loop and continuing the file transfer. 
        /// </returns>
        public static bool canPutExit()
        {
            return false;
        }

        #endregion
    }
}
