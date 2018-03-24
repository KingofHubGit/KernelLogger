package com.pax.kernel.logger;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends Activity {

	private TextView mTv = null;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		mTv = (TextView)findViewById(R.id.text_view_id);
		
		mTv.setText(LoggerController.instance().getBuildTimeFormat());
		
		LoggerController.instance().loadKernelLog("fuck",888);
		
	}
}
