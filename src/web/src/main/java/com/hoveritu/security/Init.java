package com.hoveritu.security;

import javax.annotation.PostConstruct;

import org.apache.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Scope;
import org.springframework.mail.MailSender;

import com.hoveritu.domain.User;
import com.hoveritu.util.EmailUtil;
import com.hoveritu.util.RandomUtil;

@Scope("singleton")
public class Init {
	
	private Logger log = Logger.getLogger(getClass());
	
	 @Autowired
	 private transient MailSender mailTemplate;
	 
	 @PostConstruct
	 public void init() {
		 log.info("Initializing...");
		 createUser("dmitry.igoshin@gmail.com");
		 createUser("hansson.seb@gmail.com");
	 }
	 
	 private void createUser(String email) {
		 if (User.findUsersByEmailEquals(email).getResultList().size() == 0) {
			 User user = new User();
			 user.setEmail(email);
			 String password = RandomUtil.gen(10);
			 user.setPassword(password);
			 user.persist();
			 log.info("Creating the user " + email + " with password " + password);
			 EmailUtil.sendMessage("hoveritu@gmail.com", "Hoveritu web interface welcome", email, "Welcome! Your password is: " + password, mailTemplate);
		 }
	 }
	 

}
