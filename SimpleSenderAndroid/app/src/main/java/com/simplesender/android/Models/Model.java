package com.simplesender.android.Models;

import android.util.Log;

import com.simplesender.android.Utils.EventInterface;

public class Model {
    private Reciever receiver;

    public Model() {
        receiver = new Reciever();
    }

    //Sends the message
    public void send(String address, String message) {
        new Sender().execute(address, message);
    }

    public void addListener(EventInterface e) {
        receiver.subscribe(e);
    }

    //Stats the server and waits for it to return the message it received
    public String recieve() {
        Log.i("Model:" ,"Start Listening");
        receiver.recieve();
        return "";

    }

}
