package com.androidex.plugins;

/**
 * 读取系统UEVENT事件的插件,内核驱动会把一些硬件输入操作转换为UEVENT事件上报.hwserver再将事件读取后通过/dev/hwread送给上层程序.
 * 这个插件就是通过读取/dev/hwread来获得内核驱动或者hwserver产生的UEVENT事件的.
 */

import android.app.Activity;
import android.util.Log;

public class kkuevent{
	
	static
	{
		 try {
				System.loadLibrary("Lockaxial");
			} catch (UnsatisfiedLinkError e) {
				Log.d("Debug", "uevent library not found!");
		}
	}

    Activity ctx=null;
    public kkuevent(Activity _ctx){
        ctx = _ctx;
    }

	/**
	 * 说明：该函数接收从jni层c传上来的信息并针对相应的信息发消息到js层
	 * @param _code，消息代码，如果code==0时，msg为读取到的uevent数据
	 * @param _msg，消息内容
	 */
	public void OnUEvent(int _code,String _msg){
		System.out.format("UEvent return:code=%d,msg=%s\n",_code,_msg);
		//String m = String.format("0x%08X:%s\r\n", _code,_msg);
		if ((ctx != null) && (ctx instanceof OnBackCall)) {
			OnBackCall listener = (OnBackCall) ctx;
			listener.onBackCallEvent(_code, _msg);
		}
	}

	/**
	 * 打开uevent服务端口
	 * @param subsystem  如果不为空字符串，则只有匹配的uevent事件才会通过事件返回
	 * @return  成功返回非0，否则返回0或者小于0
	 */
	public int uevent_open(String subsystem){
		int r = open(subsystem);
		return r;
	}

	/**
	 * 启动读取UEvent消息的线程
	 * @param subsystem  如果不为空字符串，且open时的不为空则只有匹配的uevent事件才会通过事件返回
	 * @return 返回读取结束的方式，一般是调用close来控制结束
	 */
	public int uevent_read(final String subsystem){
		Runnable run=new Runnable() {
			public void run() {
				int r = read(subsystem);
			}
		};
		Thread pthread = new Thread(run);
		pthread.start();

		return 0;
	}

	/**
	 * 关闭UEvent收取
	 * @return 成功返回非0，否则返回0或者小于0
	 */
	public int uevent_close(){
		int r = close();
		return r;
	}

	//jni 相关函数
	public native int  open(String subsystem);
	public native int  read(String subsystem);
	public native int  close();
}
