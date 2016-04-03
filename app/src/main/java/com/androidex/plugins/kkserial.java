package com.androidex.plugins;

/**
 * 串口操作插件,上层Java操作底层文件经常会发生权限等问题,使用此JNI插件来处理串口操作简单很多.操作方法也类似C语言的操作习惯.
 */

import android.app.Activity;
import android.util.Log;

public class kkserial {

	static
	{
		 try {
				System.loadLibrary("Lockaxial");
			} catch (UnsatisfiedLinkError e) {
				Log.d("Debug", "serial library not found!");
		}
	}

    Activity ctx=null;
    public kkserial(Activity _ctx){
        ctx = _ctx;
    }

	/**
	 * 打开串口端口
	 * @param sport  要打开串口的地址信息字符串
	 * @return  成功返回非0，否则返回0或者小于0
	 */
	public int serial_open(String sport){
		int r = open(sport);
		return r;
	}

	/**
	 * 启动读取串口数据的线程
	 * @return 返回读取结束的方式，一般是调用close来控制结束
	 */
	public byte[] serial_read(int fd, int timeout){
        return read(fd,timeout);
	}

	/**
	 * 写数据到串口
	 * @param data  要写入的数据
	 * @return 返回写入的字节数或者错误值
	 */
	public int serial_write(int fd,byte[] data,int size){
		int r = write(fd,data,size);
		return r;
	}

	/**
	 * 关闭UEvent收取
	 * @return 成功返回非0，否则返回0或者小于0
	 */
	public int serial_close(int fd){
		int r = close(fd);
		return r;
	}

	//jni 相关函数
	public native int       open(String sport);
    public native int       select(int fd, int usec);
    public native byte[]    read(int fd,int timeout);
	public native int       write(int fd,byte[] data,int size);
	public native int       close(int fd);
}
