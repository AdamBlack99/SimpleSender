package com.simplesender.android.Models;

import android.util.Log;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.EventListener;
import java.util.List;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import com.simplesender.android.Utils.EventInterface;

public class Reciever {

    private ServerSocket _server;
    private BufferedReader _bfr;
    private InputStreamReader _isr;
    private String message;
    private List<EventInterface> gotMessageListeners;

    public Reciever(){
        gotMessageListeners = new ArrayList<EventInterface>();

    }

    public void subscribe(EventInterface listener) {
        gotMessageListeners.add(listener);
    }

    //Start the server and waits until the first message arrives. While doing so, it blocks the main thread.
    //Returns the message it received as a String.
    //TODO: Rewrite it not to block the main thread.
    String recieve() {
        //BlockingQueue<String> messages = new LinkedBlockingQueue<>();
        Log.i("Server", "Setting up receiver");
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Log.i("Server: ", "Thread started");
                    _server = new ServerSocket(10000);
                    Log.i("Server: ", "Set up");

                    Socket client = _server.accept();
                    _isr = new InputStreamReader(client.getInputStream());
                    _bfr = new BufferedReader(_isr);

                    String tempMessage = "-";
                    tempMessage = _bfr.readLine();
                    Log.i("Server: ", tempMessage);

                    //messages.put(tempMessage);
                    Log.i("Server: ", "Recieved");
                    _isr.close();

                    client.close();
                    for(EventInterface e : gotMessageListeners) {
                        e.gotMessage(tempMessage);
                    }



                } catch (IOException e) {

                    if (null == e.getMessage()) {
                        Log.e("Server: ", "Fatal Error");
                    } else {
                        Log.e("Server: ", e.getMessage());
                    }
                } finally {
                    try {
                        _server.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }


                }

            }
        }).start();
        /*
        try {
            message = messages.take();
        } catch (InterruptedException e) {

            message = "";
        }

        */
        return message;
    }


}
