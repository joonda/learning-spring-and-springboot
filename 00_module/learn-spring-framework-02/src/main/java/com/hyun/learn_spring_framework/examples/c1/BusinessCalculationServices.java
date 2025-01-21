package com.hyun.learn_spring_framework.examples.c1;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;

import java.util.Arrays;

//@Component
@Service // Service logic을 설정하기때문에 @Service annotation을 해주는 것이 권장
public class BusinessCalculationServices {
    private DataService dataService; // 사용할 변수 지정

    @Autowired
    public void setDataService(DataService dataService) { //setter
        this.dataService = dataService;
    }

    public int findMax() { // 사용할 함수 로직 지정
        return Arrays.stream(dataService.retrieveData()).max().orElse(0);
    }
}
