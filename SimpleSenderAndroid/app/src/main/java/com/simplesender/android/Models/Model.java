package com.simplesender.android.Models;

import android.util.Log;

public class Model {

    public Model() {}

    //Sends the message
    public void send(String address, String message) {
        new Sender().execute(address, message);
    }


    //Stats the server and waits for it to return the message it received
    public String recieve() {
        Log.i("Model:" ,"Start Listening");
        return new Reciever().recieve();
    }

}
