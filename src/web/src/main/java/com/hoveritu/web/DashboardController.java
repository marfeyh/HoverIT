package com.hoveritu.web;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.hoveritu.domain.HovercraftState;
import com.hoveritu.util.HovercraftUtil;

@RequestMapping("/json/**")
@Controller
public class DashboardController {

	@RequestMapping(value="/json/state")
	@ResponseBody
	public Object showJson() {
		HovercraftState st = new HovercraftState();
		st.setBatteryLevel(HovercraftUtil.getBatteryLevel());
		st.setPressure(HovercraftUtil.getPressure());
		st.setSpeed(HovercraftUtil.getSpeed());
	    return st.toJson();
	}
}
