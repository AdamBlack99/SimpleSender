package com.simplesender.android.Models;

import android.os.AsyncTask;
import android.util.Log;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;


// Sends the message (the FIRST argument) to the address (SECOND argument)
public class Sender extends AsyncTask<String, Void, String> {
    private Socket _socket;
    private PrintWriter _pw;



    @Override
    protected String doInBackground(String... strings) {
        try {
            _socket = new Socket(strings[0], 10000);
            _pw = new PrintWriter(_socket.getOutputStream());
            _pw.write(strings[1]);
            _pw.flush();
            _pw.close();
            _socket.close();


        } catch (IOException e) {
            e.printStackTrace();
            Log.e("Socket:", e.getMessage());
        }
        return "";

    }
}
