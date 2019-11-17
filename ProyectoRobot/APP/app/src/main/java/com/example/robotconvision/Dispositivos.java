package com.example.robotconvision;

import androidx.appcompat.app.AppCompatActivity;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Set;

public class Dispositivos extends AppCompatActivity {

    //Depuración LOGCAT
    private static final String TAG = "Dispositivos";
    ListView Lista;
    //String que se envia a la mainactivity
    public static String EXTRA_DEVICE_ADDRESS = "device_address";

    //Declaracion de campos
    private BluetoothAdapter mBtAdapter;
    private ArrayAdapter<String> mPairedDevicesArrayAdapter;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dispositivos);


    }

    @Override
    public void onResume() {
        super.onResume();
        VerificarEstadoBT();

        //Inicializa array que contendra la lista de dispositivos
        mPairedDevicesArrayAdapter = new ArrayAdapter<String>(this, R.layout.nombre_dispositivos);
        //Presenta los dispositivos en mPaired listView
        Lista = (ListView) findViewById(R.id.LVLista);
        Lista.setAdapter(mPairedDevicesArrayAdapter);
        Lista.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                //Obtener la direccion mac del dispositivo
                String info = ((TextView) view).getText().toString();
                String address = info.substring(info.length()-17);
                //intent que pasa el adress
                Intent xd = new Intent(Dispositivos.this,MainActivity.class);
                xd.putExtra(EXTRA_DEVICE_ADDRESS,address);
                startActivity(xd);
            }
        });
        //obtiene el Adaptador local Bluetooth adapter
        mBtAdapter = BluetoothAdapter.getDefaultAdapter();
        Set<BluetoothDevice> pairedDevices = mBtAdapter.getBondedDevices();
        //adiciona un dispositivo previo emparejado al array
        if (pairedDevices.size() > 0) {
            for (BluetoothDevice device : pairedDevices) {
                mPairedDevicesArrayAdapter.add(device.getName() + "\n" + device.getAddress());
            }
        }
    }


    private void VerificarEstadoBT(){
        mBtAdapter = BluetoothAdapter.getDefaultAdapter();
        if(mBtAdapter==null){
            Toast.makeText(getBaseContext(),"No soporta Bluetooth xd pobreee",Toast.LENGTH_SHORT).show();
        }else{
            if(mBtAdapter.isEnabled()){
                Log.d(TAG,"...cargandoo....Bluetooth Activado");
            }else{
                //Solicita que active
                Intent activarBlue = new Intent(BluetoothAdapter.ACTION_REQUEST_ENABLE);
                startActivityForResult(activarBlue,1);
            }
        }

    }


}
