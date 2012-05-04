package com.hoveritu.domain;

import org.springframework.roo.addon.entity.RooEntity;
import org.springframework.roo.addon.javabean.RooJavaBean;
import org.springframework.roo.addon.tostring.RooToString;
import org.springframework.roo.addon.json.RooJson;

@RooJavaBean
@RooToString
@RooEntity
@RooJson
public class HovercraftState {

    private int Speed;

    private double BatteryLevel;

    private double Pressure;
}
