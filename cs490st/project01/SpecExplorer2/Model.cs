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
        static TFTPClient.FSM_Modes state = TFTPClient.FSM_Modes.INIT;

        [Rule(Action = "initialize()")]
        static void initialize()
        {
            state = TFTPClient.FSM_Modes.INIT;
        }

        [Rule(Action = "canGetExit(len)")]
        static void canGetExit(int len)
        {
            throw new NotImplementedException();
        }

        [Rule(Action = "canPutExit(len)")]
        static void canPutExit(int len)
        {
            throw new NotImplementedException();
        }

        [Rule(Action = "sendACK()")]
        static void sendACK()
        {
            throw new NotImplementedException();
        }

        [Rule(Action = "receiveACK()")]
        static void receiveACK()
        {
            throw new NotImplementedException();
        }

        [Rule(Action = "sendReadRequest()")]
        static void sendReadRequest()
        {
            throw new NotImplementedException();
        }

        [Rule(Action = "sendWriteRequest()")]
        static void sendWriteRequest()
        {
            throw new NotImplementedException();
        }

        [Rule(Action = "receiveDataBlock()")]
        static void receiveDataBlock()
        {
            throw new NotImplementedException();
        }

        [Rule(Action = "sendDataBlock()")]
        static void sendDataBlock()
        {
            throw new NotImplementedException();
        }
    }
}
