CREATE TABLE datalog_meteo (
    id int(10) unsigned NOT NULL AUTO_INCREMENT,
    temps timestamp NULL DEFAULT CURRENT_TIMESTAMP,
    temperature float DEFAULT NULL,
    pression float DEFAULT NULL,
    PRIAMRY KEY (id)
) ENGINE=InnoDB;
