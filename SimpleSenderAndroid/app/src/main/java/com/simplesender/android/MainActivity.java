package com.simplesender.android;

import android.graphics.Color;
import android.os.Bundle;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.util.Log;
import android.view.View;

import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.TextView;
import com.simplesender.android.Models.Model;
import com.simplesender.android.Utils.EventInterface;

public class MainActivity extends AppCompatActivity implements EventInterface{
    private Model _model;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        _model = new Model();
        _model.addListener(this);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

   public void onSendClick(View view) {
       EditText address = (EditText)findViewById(R.id.addressInput);
       EditText message = (EditText)findViewById(R.id.messageInput);

       _model.send(address.getText().toString(), message.getText().toString());


   }



    public void onListenClick(View view) {

        Log.i("Ui:" ,"Start Listening");
        Button button = (Button)findViewById(R.id.listenButton);
        button.setText("Listening");
        _model.recieve();



    }

    public void gotMessage(String message) {
        EditText messageBox = (EditText)findViewById(R.id.messageOutput);
        Button button = (Button)findViewById(R.id.listenButton);
        messageBox.setText(message);
        button.setText("Recieve");


    }

}