using System;
using System.Collections.Generic;
using System.Text;

using Microsoft.Modeling;
using TFTPClientNameSpace;

namespace SpecExplorer2
{
    [TypeBinding("SpecExplorer2.TFTPClientAdapter")]
    public class ModelProgram
    {
        static TFTPClient.FSM_Modes state = TFTPClient.FSM_Modes.INIT;

        [Rule(Action = "initialize()")]
        static void initialize()
        {
            state = TFTPClient.FSM_Modes.INIT;
        }

        [Rule(Action = "TFTPClientAdapter.canGetExit(len)")]
        static void canGetExit(int len)
        {
            if (len < 516)
                state = TFTPClient.FSM_Modes.EXIT;
        }

        [Rule(Action = "TFTPClientAdapter.canPutExit(len)")]
        static void canPutExit(int len)
        {
            if (len < 516)
                state = TFTPClient.FSM_Modes.EXIT;
        }

        [Rule(Action = "sendACK()")]
        static void sendACK()
        {
            Condition.IsTrue(state == TFTPClient.FSM_Modes.DATA_RECEIVED);
            state = TFTPClient.FSM_Modes.ACK_SENT;
        }

        [Rule(Action = "receiveACK()")]
        static void receiveACK()
        {
            Condition.IsTrue(state == TFTPClient.FSM_Modes.WRQ_SENT ||
                             state == TFTPClient.FSM_Modes.DATA_SENT);
            state = TFTPClient.FSM_Modes.ACK_RECEIVED;
        }

        [Rule(Action = "sendReadRequest()")]
        static void sendReadRequest()
        {
            Condition.IsTrue(state == TFTPClient.FSM_Modes.INIT);
            state = TFTPClient.FSM_Modes.RRQ_SENT;
        }

        [Rule(Action = "sendWriteRequest()")]
        static void sendWriteRequest()
        {
            Condition.IsTrue(state == TFTPClient.FSM_Modes.INIT);
            state = TFTPClient.FSM_Modes.WRQ_SENT;
        }

        [Rule(Action = "receiveDataBlock()")]
        static void receiveDataBlock()
        {
            Condition.IsTrue(state == TFTPClient.FSM_Modes.RRQ_SENT ||
                             state == TFTPClient.FSM_Modes.ACK_SENT);
            state = TFTPClient.FSM_Modes.DATA_RECEIVED;
        }

        [Rule(Action = "sendDataBlock()")]
        static void sendDataBlock()
        {
            Condition.IsTrue(state == TFTPClient.FSM_Modes.ACK_RECEIVED);
            state = TFTPClient.FSM_Modes.DATA_SENT;
        }

        [Rule]
        static void checker(int tftpMode)
        {
            Condition.IsTrue((int)state == tftpMode);
        }
    }
}
