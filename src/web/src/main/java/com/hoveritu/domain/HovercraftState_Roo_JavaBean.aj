// WARNING: DO NOT EDIT THIS FILE. THIS FILE IS MANAGED BY SPRING ROO.
// You may push code into the target .java compilation unit if you wish to edit any member(s).

package com.hoveritu.domain;

import com.hoveritu.domain.HovercraftState;

privileged aspect HovercraftState_Roo_JavaBean {
    
    public int HovercraftState.getSpeed() {
        return this.Speed;
    }
    
    public void HovercraftState.setSpeed(int Speed) {
        this.Speed = Speed;
    }
    
    public double HovercraftState.getBatteryLevel() {
        return this.BatteryLevel;
    }
    
    public void HovercraftState.setBatteryLevel(double BatteryLevel) {
        this.BatteryLevel = BatteryLevel;
    }
    
    public double HovercraftState.getPressure() {
        return this.Pressure;
    }
    
    public void HovercraftState.setPressure(double Pressure) {
        this.Pressure = Pressure;
    }
    
    public double HovercraftState.getLatitude() {
        return this.latitude;
    }
    
    public void HovercraftState.setLatitude(double latitude) {
        this.latitude = latitude;
    }
    
    public double HovercraftState.getLongitude() {
        return this.longitude;
    }
    
    public void HovercraftState.setLongitude(double longitude) {
        this.longitude = longitude;
    }
    
}
