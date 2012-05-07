package com.hoveritu.web;

import com.hoveritu.domain.HovercraftState;
import org.springframework.roo.addon.web.mvc.controller.scaffold.RooWebScaffold;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

@RooWebScaffold(path = "hovercraftstates", formBackingObject = HovercraftState.class)
@RequestMapping("/hovercraftstates")
@Controller
public class HovercraftStateController {
	
}
