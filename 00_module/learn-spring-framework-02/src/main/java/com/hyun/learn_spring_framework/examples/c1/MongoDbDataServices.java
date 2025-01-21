package com.hyun.learn_spring_framework.examples.c1;

import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;

//@Component
@Repository // @Component 보다는 Repository를 권장
            // DB와 통신하는 경우이기 때문에
@Primary
public class MongoDbDataServices implements DataService{
    @Override
    public int[] retrieveData() {
        return new int[] {11, 22, 33, 44, 55};
    }
}
