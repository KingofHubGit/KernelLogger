package com.pax.kernel.logger;

public class LoggerController {
	
	private final static String TAG = "LoggerController";
	private static LoggerController mLoggerController;

	static {
		System.loadLibrary("jni_pax_dmesg");
	}
	
	public native String getLogString();
	public native void loadKernelLog(String str, int x);
	
	private LoggerController() {
		
	}

	public static LoggerController instance() {
		if (mLoggerController == null)
			mLoggerController = new LoggerController();
		return mLoggerController;
	}
	
	public String getBuildTimeFormat() {
		String[] month = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
				"Aug", "Sep", "Oct", "Nov", "Dec" };
		String s = getLogString();

		int m = 1;
		for (int i = 0; i < month.length; i++) {
			if (s.contains(month[i])) {
				m = i + 1;
				break;
			}
		}

		return s.substring(7, 11) + String.format("/%02d/", m)
				+ s.substring(4, 6).replace(' ', (char) 0x30)
				+ s.substring(11, s.length());
	}
	
	public void getKernelLog(String str1,int x) {
		loadKernelLog(str1,x);
	}
	

	
}
