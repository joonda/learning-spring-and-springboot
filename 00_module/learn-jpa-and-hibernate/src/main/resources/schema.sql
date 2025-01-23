create table course
(
    id bigint not null, -- bigint > long
    name varchar(255) not null,
    author varchar(255) not null,
    primary key (id)
);