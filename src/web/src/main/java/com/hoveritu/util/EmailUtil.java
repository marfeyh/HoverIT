package com.hoveritu.util;

import org.apache.log4j.Logger;
import org.springframework.mail.MailSender;
public class EmailUtil {
	
	
	private static Logger log = Logger.getLogger(EmailUtil.class);
	
	public static void sendMessage(String mailFrom, String subject, String mailTo,
			String message, MailSender mailTemplate) {
		org.springframework.mail.SimpleMailMessage simpleMailMessage = new org.springframework.mail.SimpleMailMessage();
		simpleMailMessage.setFrom(mailFrom);
		simpleMailMessage.setSubject(subject);
		simpleMailMessage.setTo(mailTo);
		simpleMailMessage.setText(message);
		try {
		mailTemplate.send(simpleMailMessage);
		} catch (Exception e) {
			log.error("Exception while sending mail", e);
		}
	}	
	
}
