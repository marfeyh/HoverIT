package com.hoveritu.domain;

import org.springframework.roo.addon.javabean.RooJavaBean;
import org.springframework.roo.addon.jpa.activerecord.RooJpaActiveRecord;
import org.springframework.roo.addon.json.RooJson;
import org.springframework.roo.addon.tostring.RooToString;

@RooJavaBean
@RooToString
@RooJpaActiveRecord
@RooJson
public class HovercraftState {

    private int Speed;

    private double BatteryLevel;

    private double Pressure;

    private double latitude;

    private double longitude;
}
