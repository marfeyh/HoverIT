package com.hoveritu.util;
/**
 * Communicates with the hovercraft 
 * @author Dmitry Igoshin
 * @todo return real values instead of random
 */
public class HovercraftUtil {

	/**
	 * Returns speed
	 * @return int current hovercraft speed 
	 */
	public static int getSpeed() {
		return (int)(Math.random() * 7);
	}

	/**
	 * Returns pressure
	 * @return int current hovercraft pressure 
	 */
	public static double getPressure() {
		return Math.random() * 100;
	}
	
	/**
	 * Returns battery level
	 * @return int current battery level 
	 */
	public static double getBatteryLevel() {
		return Math.random() * 100;
	}
}
