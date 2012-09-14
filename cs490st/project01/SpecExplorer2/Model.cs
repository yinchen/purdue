using System;
using System.Collections.Generic;
using System.Text;

using Microsoft.Modeling;
using TFTPClientNameSpace;

namespace SpecExplorer2
{
    [TypeBinding("TFTPClientNameSpace.TFTPClient")]
    public class ModelProgram
    {
        static TFTPClientAdapter.FSM_Modes state = TFTPClientAdapter.FSM_Modes.INIT;

        [Rule(Action = "initialize()")]
        static void initialize()
        {
            state = TFTPClientAdapter.FSM_Modes.INIT;
        }

        [Rule(Action = "canGetExit(len)")]
        static void canGetExit(int len)
        {
            if (len < 516)
                state = TFTPClientAdapter.FSM_Modes.EXIT;
        }

        [Rule(Action = "canPutExit(len)")]
        static void canPutExit(int len)
        {
            if (len < 516)
                state = TFTPClientAdapter.FSM_Modes.EXIT;
        }

        [Rule(Action = "sendACK()")]
        static void sendACK()
        {
            Condition.IsTrue(state == TFTPClientAdapter.FSM_Modes.DATA_RECEIVED);
            state = TFTPClientAdapter.FSM_Modes.ACK_SENT;
        }

        [Rule(Action = "receiveACK()")]
        static void receiveACK()
        {
            Condition.IsTrue(state == TFTPClientAdapter.FSM_Modes.WRQ_SENT ||
                             state == TFTPClientAdapter.FSM_Modes.DATA_SENT);
            state = TFTPClientAdapter.FSM_Modes.ACK_RECEIVED;
        }

        [Rule(Action = "sendReadRequest()")]
        static void sendReadRequest()
        {
            Condition.IsTrue(state == TFTPClientAdapter.FSM_Modes.INIT);
            state = TFTPClientAdapter.FSM_Modes.RRQ_SENT;
        }

        [Rule(Action = "sendWriteRequest()")]
        static void sendWriteRequest()
        {
            Condition.IsTrue(state == TFTPClientAdapter.FSM_Modes.INIT);
            state = TFTPClientAdapter.FSM_Modes.WRQ_SENT;
        }

        [Rule(Action = "receiveDataBlock()")]
        static void receiveDataBlock()
        {
            Condition.IsTrue(state == TFTPClientAdapter.FSM_Modes.RRQ_SENT ||
                             state == TFTPClientAdapter.FSM_Modes.ACK_SENT);
            state = TFTPClientAdapter.FSM_Modes.DATA_RECEIVED;
        }

        [Rule(Action = "sendDataBlock()")]
        static void sendDataBlock()
        {
            Condition.IsTrue(state == TFTPClientAdapter.FSM_Modes.ACK_RECEIVED);
            state = TFTPClientAdapter.FSM_Modes.DATA_SENT;
        }
    }
}
