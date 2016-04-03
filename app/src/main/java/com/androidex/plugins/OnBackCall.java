package com.androidex.plugins;

public interface OnBackCall {
	
    /**
     * 	用于插件调用主activity
     * @param code		事件代码
     * @param args		字符串
     */
	public void onBackCallEvent(int code,String args);
}
