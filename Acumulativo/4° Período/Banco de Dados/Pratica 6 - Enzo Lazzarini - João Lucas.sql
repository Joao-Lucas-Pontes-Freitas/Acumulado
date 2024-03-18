SET search_path TO universidade;
SHOW datestyle;
SET datestyle TO 'mdy';

-- Faculdade
INSERT INTO faculdade (sigla, nome, predio, orcamento) values ('FACOM', 'Universidade Federal de Uberlândia', '1B', 1000000);

-- Disciplinas
INSERT INTO disciplina (codigo, nome, fac_disc, ch) values ('GBC024', 'AED1', 'FACOM', 90);
INSERT INTO disciplina (codigo, nome, fac_disc, ch) values ('GBC043', 'SBD', 'FACOM', 90);
INSERT INTO disciplina (codigo, nome, fac_disc, ch) values ('GBC034', 'AED2', 'FACOM', 60);
INSERT INTO disciplina (codigo, nome, fac_disc, ch) values ('GBC035', 'POO1', 'FACOM', 60);
INSERT INTO disciplina (codigo, nome, fac_disc, ch) values ('GBC055', 'POO2', 'FACOM', 60);

-- Pré-Requisito
INSERT INTO pre_requisito (cod_disc, cod_pre) values ('GBC055', 'GBC035');
INSERT INTO pre_requisito (cod_disc, cod_pre) values ('GBC034', 'GBC024');

-- Professores
INSERT INTO professor (id, nome, fac_prof, admissao) values ('AAAAAAAAAAA', 'Maria', 'FACOM', CURRENT_DATE);
INSERT INTO professor (id, nome, fac_prof, admissao) values ('AAAAAAAAAAB', 'Carlos', 'FACOM', CURRENT_DATE);
INSERT INTO professor (id, nome, fac_prof, admissao) values ('AAAAAAAAABB', 'Jorge', 'FACOM', CURRENT_DATE);
INSERT INTO professor (id, nome, fac_prof, admissao) values ('AAAAAAAABBB', 'Júlia', 'FACOM', CURRENT_DATE);
INSERT INTO professor (id, nome, fac_prof, admissao) values ('AAAAAAABBBB', 'Marcos', 'FACOM', CURRENT_DATE);

-- Estudante
INSERT INTO estudante (id, nome, datanasc, fac_est, cra, tutor) values ('12121BCC001', 'Marcelo', '01/01/2004', 'FACOM', 95, NULL);
INSERT INTO estudante (id, nome, datanasc, fac_est, cra, tutor) values ('12121BCC002', 'Ana', '02/02/2004', 'FACOM', 96, 'AAAAAAAAABB');
INSERT INTO estudante (id, nome, datanasc, fac_est, cra, tutor) values ('12121BCC003', 'Pedro', '03/03/2004', 'FACOM', 94.5, 'AAAAAAAABBB');
INSERT INTO estudante (id, nome, datanasc, fac_est, cra, tutor) values ('12121BCC004', 'João', '04/04/2004', 'FACOM', 98, NULL);
INSERT INTO estudante (id, nome, datanasc, fac_est, cra, tutor) values ('12121BCC005', 'Luiza', '10/01/2004', 'FACOM', 92.9, NULL);

-- Sala
INSERT INTO sala (predio, numero, capacidade) values ('1B', 202, 60);
INSERT INTO sala (predio, numero, capacidade) values ('1B', 204, 60);
INSERT INTO sala (predio, numero, capacidade) values ('1B', 206, 60);

-- Turma
INSERT INTO turma (id, turma, semestre, ano, cod_disc, predio_s, n_sala) values (1, 'C', 20231, 2023, 'GBC024', '1B', 204);
INSERT INTO turma (id, turma, semestre, ano, cod_disc, predio_s, n_sala) values (2, 'E', 20231, 2023, 'GBC024', '1B', 202);
INSERT INTO turma (id, turma, semestre, ano, cod_disc, predio_s, n_sala) values (3, 'C', 20231, 2023, 'GBC043', '1B', 204);
INSERT INTO turma (id, turma, semestre, ano, cod_disc, predio_s, n_sala) values (4, 'C', 20231, 2023, 'GBC035', '1B', 204);
INSERT INTO turma (id, turma, semestre, ano, cod_disc, predio_s, n_sala) values (5, 'C', 20231, 2023, 'GBC055', '1B', 206);

-- Semana
INSERT INTO semana (id_sem, descricao) values (1, 'Domingo');
INSERT INTO semana (id_sem, descricao) values (2, 'Segunda');
INSERT INTO semana (id_sem, descricao) values (3, 'Terça');
INSERT INTO semana (id_sem, descricao) values (4, 'Quarta');
INSERT INTO semana (id_sem, descricao) values (5, 'Quinta');
INSERT INTO semana (id_sem, descricao) values (6, 'Sexta');
INSERT INTO semana (id_sem, descricao) values (7, 'Sábado');

-- Horario
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('a', '07:10:00', '08:00:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('b', '08:00:00', '08:50:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('c', '08:50:00', '09:40:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('d', '09:50:00', '10:40:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('e', '10:40:00', '11:30:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('q', '11:30:00', '12:20:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('f', '13:10:00', '14:00:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('g', '14:00:00', '14:50:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('h', '14:50:00', '15:40:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('i', '16:00:00', '16:50:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('j', '16:50:00', '17:40:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('k', '17:40:00', '18:30:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('l', '18:10:00', '19:00:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('m', '19:00:00', '19:50:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('n', '19:50:00', '20:40:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('o', '20:50:00', '21:40:00');
INSERT INTO horario (id_hora, hora_inicio, hora_fim) values ('p', '21:40:00', '22:30:00');

-- Horario Aula
INSERT INTO horario_aula (id_sem, id_turma, id_hora) values (2, 1, 'h');
INSERT INTO horario_aula (id_sem, id_turma, id_hora) values (2, 1, 'i');
INSERT INTO horario_aula (id_sem, id_turma, id_hora) values (4, 1, 'h');
INSERT INTO horario_aula (id_sem, id_turma, id_hora) values (4, 1, 'i');
INSERT INTO horario_aula (id_sem, id_turma, id_hora) values (4, 1, 'j');
INSERT INTO horario_aula (id_sem, id_turma, id_hora) values (4, 1, 'k');

-- Frequenta
INSERT INTO frequenta (id_est, id_turma, nota) values ('12121BCC001', 1, 97);
INSERT INTO frequenta (id_est, id_turma, nota) values ('12121BCC002', 1, 78);
INSERT INTO frequenta (id_est, id_turma, nota) values ('12121BCC003', 1, 99);
INSERT INTO frequenta (id_est, id_turma, nota) values ('12121BCC004', 1, 87);
INSERT INTO frequenta (id_est, id_turma, nota) values ('12121BCC005', 1, 92);

-- Ensina
INSERT INTO ensina (id_prof, id_turma) values ('AAAAAAAAAAA', 1);
INSERT INTO ensina (id_prof, id_turma) values ('AAAAAAAAAAB', 2);
INSERT INTO ensina (id_prof, id_turma) values ('AAAAAAAAABB', 3);
INSERT INTO ensina (id_prof, id_turma) values ('AAAAAAAABBB', 4);
INSERT INTO ensina (id_prof, id_turma) values ('AAAAAAABBBB', 5);
