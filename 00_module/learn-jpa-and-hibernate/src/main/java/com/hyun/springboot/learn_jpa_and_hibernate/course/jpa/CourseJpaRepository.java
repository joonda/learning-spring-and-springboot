package com.hyun.springboot.learn_jpa_and_hibernate.course.jpa;

import com.hyun.springboot.learn_jpa_and_hibernate.course.Course;
import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;
import jakarta.transaction.Transactional;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
@Transactional // Entity Manager는 트랜잭션이 필요하다.
public class CourseJpaRepository {

    @PersistenceContext // Autowired를 써도 되지만, 더 구체적인 Annotation 사용.
    private EntityManager entityManager;

    // Course를 매개 변수로 받는다.
    public void insert(Course course) {

        // merge로 Course와 Mapping
        entityManager.merge(course);
    }

    // Course 타입을 반환
    // Course.class -> Course 클래스를 나타내는 클래스 객체, 매핑 과정에서 사용한다
    public Course findById(long id) {
        return entityManager.find(Course.class, id);
    }

    // Delete 방식은 조금 복잡하다
    public void deleteById(long id) {
        // 엔터티를 먼저 찾는다.
        // 이걸 지역 변수에 담는다.
        Course course = entityManager.find(Course.class, id);

        // 해당 엔터티를 remove
        entityManager.remove(course);
    }

    public List<Course> findAll() {
        return entityManager.createQuery("select c from Course c", Course.class).getResultList();
    }
}
