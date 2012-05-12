/* *@author : Aida Monzavi,Massih Mozahhebi
 * This Activity use permission.INTERNET to be able to use network package
 * <uses-permission android:name="android.permission.INTERNET" />
 * this activity get IP and port from user and try to 
 * create network socket and necessary input and output streams
 */
package com.hovercraft.android.wifi;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;


public class WiFiActivity extends Activity {
	private EditText ipEditText;
	private Button conncetButton;
	private EditText portEditText;
	private AlertDialog askedConncetDialog;
	protected boolean changesPending;

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		setUpView();
	}
/*
 * This function called when user press CONNECT button 
 * get IP and Port from EditText and create a network socket according to them.
 * Then create input and output stream to send and receive data
 */
	protected void conncet() {
				String ipAddress = ipEditText.getText().toString();
				String port = portEditText.getText().toString();
//				Socket soc = new Socket("192.168.1.2", port);
				Socket soc;
				try {
					soc = new Socket(ipAddress, Integer.parseInt(port));
					DataInputStream din = new DataInputStream(soc.getInputStream());
					DataOutputStream dout = new DataOutputStream(soc.getOutputStream());
					for (int i = 0; i < 5; i++) {
						Thread.sleep(2000);
						dout.writeByte('d');
					}
					soc.close();
					din.close();
					dout.close();
				} catch (Exception e) {
					e.printStackTrace();
				}

		if(changesPending){
			askedConncetDialog = new AlertDialog.Builder(WiFiActivity.this)
			.setTitle(R.string.connect_wifi_title)
			.setMessage(R.string.connect_wifi_message)
			.setPositiveButton(R.string.connect, new AlertDialog.OnClickListener(){
				public void onClick(DialogInterface dialog, int which){
					//connect();
				}

			})
			.setNeutralButton((Integer) R.string.discard, new AlertDialog.OnClickListener(){
				public void onClick(DialogInterface dialog, int which){
					askedConncetDialog.cancel();
				}
			})
			.setNegativeButton(android.R.string.cancel, new AlertDialog.OnClickListener(){
				public void onClick(DialogInterface dialog, int which){
					askedConncetDialog.cancel();
				}
			})
			.create();
			askedConncetDialog.show();

		}else{
			finish();}
	}

	private void setUpView() {
		ipEditText = (EditText) findViewById(R.id.ip);
		portEditText = (EditText) findViewById(R.id.port);
		conncetButton = (Button) findViewById(R.id.connect);
		conncetButton.setOnClickListener(new View.OnClickListener() {
			@Override
			public void onClick(View v) {
				conncet();
			}
		});
		ipEditText.addTextChangedListener(new TextWatcher() {

			@Override
			public void afterTextChanged(Editable s) {
				// TODO Auto-generated method stub

			}

			@Override
			public void beforeTextChanged(CharSequence s, int start, int count,
					int after) {
				// TODO Auto-generated method stub

			}

			@Override
			public void onTextChanged(CharSequence s, int start, int before,
					int count) {
				changesPending = true;

			}

		});
		portEditText.addTextChangedListener(new TextWatcher() {

			@Override
			public void afterTextChanged(Editable s) {
				// TODO Auto-generated method stub

			}

			@Override
			public void beforeTextChanged(CharSequence s, int start, int count,
					int after) {
				// TODO Auto-generated method stub

			}

			@Override
			public void onTextChanged(CharSequence s, int start, int before,
					int count) {
				changesPending = true;

			}

		});

	}

}