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
        public static void sendDataBlockAdaptor()
        {
            // initialize FTP client
            TFTPClient client = new TFTPClient("127.0.0.1");

            string localFile = "sample.txt";
            BinaryReader fileStream = new BinaryReader(new FileStream(localFile, FileMode.Open, FileAccess.Read, FileShare.ReadWrite));
            
            byte[] sndBuffer;
            client.sendDataBlock(fileStream, out sndBuffer);
        }
    }
}
