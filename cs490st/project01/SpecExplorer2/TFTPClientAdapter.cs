using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using TFTPClientNameSpace;
using System.IO;

using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace SpecExplorer2
{
    public class TFTPClientAdapter
    {
        public static TFTPClient.FSM_Modes state;
        public static TFTPClient client = new TFTPClient("127.0.0.1");

        public static void checker(int tftpClientState)
        {
            Assert.AreEqual((int)state, tftpClientState, "State mismatch: Model vs Implementation");
        }

        /// <summary>
        /// Initialze the TFTP client. Set the state to be INIT
        /// </summary>
        public static void initialize()
        {
            client.initialize();

            state = client.tftpClientMode;
        }

        /// <summary>
        /// Send Read Request. It creates the TFTP read request packet, send the packet. INIT --> RRQ_SENT.
        /// </summary>
        /// <param name="remoteFile">The remote file.</param>
        /// <param name="localFile">The local file.</param>
        /// <param name="tftpMode">The TFTP mode, NetAscii, Octet, Mail.</param>
        public static void sendReadRequest()
        {
            client.sendReadRequest("remote.txt", "local.txt", TFTPClient.Modes.NetAscii);

            state = client.tftpClientMode;
        }

        /// <summary>
        /// Receive Data Block from the TFTP server. RRQ_SENT or ACK_SENT --> DATA_RECEIVED.
        /// </summary>
        /// <param name="rcvBuffer">the receiving buffer for return.</param>
        /// <returns>
        /// A int variable that tell the length of the receiving buffer. 
        /// </returns>
        public static void receiveDataBlock()
        {
            byte[] rcvBuffer;
            client.receiveDataBlock(out rcvBuffer);

            state = client.tftpClientMode;
        }

        /// <summary>
        /// Send ACK packet to the TFTP server, after successfully receive the data block from the TFTP server. DATA_RECEIVED --> ACK_SENT.
        /// </summary>
        public static void sendACK()
        {
            client.sendACK();

            state = client.tftpClientMode;
        }

        /// <summary>
        /// check whether it is time to successfully exit. If yes, current state --> EXIT; otherwise, keep the current state.
        /// </summary>
        /// <param name="len">The length of receving buffer.</param>
        /// <returns>
        /// A bool variable indicating whether it is time to successfully exit. It is TRUE for successfully exit, FALSE for staying in the loop and continuing the file transfer. 
        /// </returns>
        public static void canGetExit(int len)
        {
            client.canGetExit(len);

            state = client.tftpClientMode;
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
            string localFile = "local.txt";
            BinaryReader fileStream = new BinaryReader(new FileStream(localFile, FileMode.Open, FileAccess.Read, FileShare.ReadWrite));

            byte[] sndBuffer;
            client.sendWriteRequest("remote.txt", "local.txt", TFTPClient.Modes.NetAscii, out sndBuffer);

            state = client.tftpClientMode;
        }

        /// <summary>
        /// Send Data Block. ACK_RECEIVED --> DATA_SENT.
        /// </summary>
        /// <param name="fileStream">The file stream for writting the downloading file.</param>
        /// <param name="sndBuffer">The returned sending buffer.</param>
        public static void sendDataBlock()
        {
            string localFile = "local.txt";
            BinaryReader fileStream = new BinaryReader(new FileStream(localFile, FileMode.Open, FileAccess.Read, FileShare.ReadWrite));

            byte[] sndBuffer;
            client.sendDataBlock(fileStream, out sndBuffer);

            state = client.tftpClientMode;
        }

        /// <summary>
        /// Receive ACK from the server. WRQ_SENT or DATA_SENT --> ACK_RECEIVED
        /// </summary>
        /// <param name="rcvBuffer">The receiving buffer.</param>
        /// <returns>
        /// A int variable that tell the length of the receiving buffer. 
        /// </returns>
        public static void receiveACK()
        {
            byte[] rcvBuffer;
            client.receiveACK(out rcvBuffer);

            state = client.tftpClientMode;
        }

        /// <summary>
        /// check whether it is time to successfully exit. If yes, current state --> EXIT; otherwise, keep the current state unchanged. 
        /// </summary>
        /// <param name="len">The length of the sending buffer.</param>
        /// <returns>
        /// A bool variable indicating whether it is time to successfully exit. It is TRUE for successfully exit, FALSE for staying in the loop and continuing the file transfer. 
        /// </returns>
        public static void canPutExit(int len)
        {
            client.canPutExit(len);

            state = client.tftpClientMode;
        }
    }
}
