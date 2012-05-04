package com.hoveritu.util;

import org.junit.Test;

import junit.framework.Assert;

public class HovercraftUtilTest {

	@Test
	public void getSpeedTest() {
		int speed;
		speed = HovercraftUtil.getSpeed();
		Assert.assertTrue("Speed not within the bounds: " + speed,
				(speed >= Constants.MIN_SPEED && speed <= Constants.MAX_SPEED));
	}

	@Test
	public void getPressureTest() {
		double pressure;
		pressure = HovercraftUtil.getSpeed();
		Assert.assertTrue("Pressure not within the bounds: " + pressure,
				(pressure >= Constants.MIN_PRESSURE && pressure <= Constants.MAX_PRESSURE));
	}

	@Test
	public void getBatteryLevelTest() {
		double batteryLevel;
		batteryLevel = HovercraftUtil.getSpeed();
		Assert.assertTrue("Pressure not within the bounds: " + batteryLevel,
				(batteryLevel >= Constants.MIN_BATTERY_LEVEL && batteryLevel <= Constants.MAX_BATTERY_LEVEL));
	}
}
