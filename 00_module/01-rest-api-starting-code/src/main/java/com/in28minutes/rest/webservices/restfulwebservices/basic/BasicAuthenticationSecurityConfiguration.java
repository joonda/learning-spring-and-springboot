package com.in28minutes.rest.webservices.restfulwebservices.basic;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.Customizer;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.http.SessionCreationPolicy;
import org.springframework.security.web.SecurityFilterChain;

@Configuration
public class BasicAuthenticationSecurityConfiguration {

    // Filter chain
    // Authenticate all requests
    // basic authentication
    // disabling csrf
    // stateless rest api

    @Bean
    public SecurityFilterChain filterChain(HttpSecurity http) throws Exception {
        return
            http
                .authorizeHttpRequests(
                // 모든 HTTP 요청이 인증이 되어야만 가능함.
                    auth -> auth.anyRequest().authenticated())
                // HTTP 기본 인증
                // 팝업 형태로 띄워줌
                .httpBasic(Customizer.withDefaults())
                // 상태가 없는 세션 만듦
                .sessionManagement(
                    session -> session.sessionCreationPolicy
                            (SessionCreationPolicy.STATELESS))
                // csrf를 해제
                .csrf().disable()
                .build();
    }
}
