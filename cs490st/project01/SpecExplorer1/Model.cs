using System;
using System.Collections.Generic;
using System.Text;

using Microsoft.Modeling;

namespace SpecExplorer1
{
    /// <summary>
    /// An example model program.
    /// </summary>
    [TypeBinding("TFTPClientNameSpace.TFTPClient")]
    class ModelProgram
    {
        // [Rule(Action = "Get(remoteFile, localFile)/result")]
        void Get(string remoteFile, string localFile)
        {

        }
    }
}
