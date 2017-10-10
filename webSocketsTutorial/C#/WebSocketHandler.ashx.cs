﻿using System;
using System.Linq;
using System.Net.WebSockets;
using System.Threading;
using System.Threading.Tasks;
using System.Web;
using System.Web.WebSockets;

namespace SimpleWebSocketApplication
{
    public class WebSocketHandler : IHttpHandler
    {
        public void ProcessRequest(HttpContext context)
        {
            //Checks if the query is WebSocket request. 
            if (context.IsWebSocketRequest)
            {
                //If yes, we attach the asynchronous handler.
                context.AcceptWebSocketRequest(WebSocketRequestHandler);
            }
        }

        public bool IsReusable { get { return false; } }

        //Asynchronous request handler.
        public async Task WebSocketRequestHandler(AspNetWebSocketContext webSocketContext)
        {
            //Gets the current WebSocket object.
            WebSocket webSocket = webSocketContext.WebSocket;

            /*We define a certain constant which will represent
            size of received data. It is established by us and 
            we can set any value. We know that in this case the size of the sent
            data is very small.
            */
            const int maxMessageSize = 1024;

            //Buffer for received bits.
            var receivedDataBuffer = new ArraySegment<Byte>(new Byte[maxMessageSize]);

            var cancellationToken = new CancellationToken();

            //Checks WebSocket state.
            while (webSocket.State == WebSocketState.Open)
            {
                //Reads data.
                WebSocketReceiveResult webSocketReceiveResult =
                  await webSocket.ReceiveAsync(receivedDataBuffer, cancellationToken);
                
                //If input frame is cancelation frame, send close command.
                if (webSocketReceiveResult.MessageType == WebSocketMessageType.Close)
                {
                    await webSocket.CloseAsync(WebSocketCloseStatus.NormalClosure,
                      String.Empty, cancellationToken);
                }
                else
                {
                    byte[] payloadData = receivedDataBuffer.Array.Where(b => b != 0).ToArray();
                    
                    //Because we know that is a string, we convert it.
                    string receiveString =
                      System.Text.Encoding.UTF8.GetString(payloadData, 0, payloadData.Length);
                    
                    //Converts string to byte array.
                    var newString =
                      String.Format("Hello, " + receiveString + " ! Time {0}", DateTime.Now.ToString());
                    Byte[] bytes = System.Text.Encoding.UTF8.GetBytes(newString);
                    
                    //Sends data back.
                    await webSocket.SendAsync(new ArraySegment<byte>(bytes),
                      WebSocketMessageType.Text, true, cancellationToken);
                }
            }
        }
    }
}