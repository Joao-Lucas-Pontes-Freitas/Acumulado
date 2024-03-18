SET search_path TO universidade;

--- QUESTÃO 1)
	-- a
SELECT D.nome, F.nome FROM disciplina D, faculdade F
WHERE D.fac_disc = F.sigla;
	-- b
SELECT D.nome, T.* FROM disciplina D, turma T
WHERE D.codigo = T.cod_disc;
	-- c
SELECT E.nome as Aluno, P.nome as Tutor FROM estudante E, professor P
WHERE E.tutor = P.id;
	-- d
SELECT DISTINCT D.nome as disciplina FROM disciplina D, turma T
WHERE T.ano = 2023 and T.semestre = 1 and D.codigo = T.cod_disc;
	-- e
SELECT D.nome as Nome_Disc, P.codigo as Codigo_Pre_Req FROM disciplina D, disciplina P, pre_requisito
WHERE cod_disc = D.codigo and cod_pre = P.codigo;
	-- f
SELECT P.nome as Nome_Pre_Req, D.codigo as Codigo_Disc FROM disciplina D, disciplina P, pre_requisito
WHERE cod_disc = D.codigo and cod_pre = P.codigo;


--- QUESTÃO 2)
-- a)
SELECT P.nome, D.nome FROM professor P, ensina E, turma T, disciplina D
WHERE P.id = E.id_prof
 	AND E.id_turma = T.id
	AND T.cod_disc = D.codigo;
  
-- b)
SELECT P.nome, D.nome FROM professor P, ensina E, turma T, disciplina D
WHERE P.id = E.id_prof
	AND E.id_turma = T.id
	AND T.cod_disc = D.codigo
	AND T.ano = 2023
	AND T.semestre = 1;
 
-- c)
SELECT DISTINCT D.nome FROM turma T, sala S, disciplina D
WHERE S.capacidade > 10
	AND T.n_sala = S.numero
	AND T.predio_s = S.predio
	AND T.cod_disc = D.codigo;
	
-- d)
SELECT estudante.nome, faculdade.nome, professor.nome FROM estudante, faculdade, professor
WHERE estudante.fac_est = faculdade.sigla
	AND estudante.tutor = professor.id;
	
	
--- QUESTÃO 3)
	-- a
SELECT D.nome as nome_disciplina, F.nome as nome_faculdade
FROM disciplina D
INNER JOIN faculdade F ON D.fac_disc = F.sigla;
	-- b
SELECT D.nome as nome_disciplina, T.*
FROM disciplina D
INNER JOIN turma T ON D.codigo = T.cod_disc;
	-- c
SELECT E.nome as Aluno, P.nome as Tutor 
FROM estudante E
INNER JOIN professor P ON E.tutor = P.id;
	-- d
SELECT DISTINCT D.nome as disciplina FROM disciplina D
INNER JOIN turma T ON D.codigo = T.cod_disc
WHERE T.ano = 2023 and T.semestre = 1;
	-- e
SELECT D.nome as Nome_Disc, P.codigo as Codigo_Pre_Req 
FROM pre_requisito
			INNER JOIN 
		disciplina D ON cod_disc = D.codigo
			INNER JOIN 
		disciplina P ON cod_pre = P.codigo;
	-- f
SELECT P.nome as Nome_Pre_Req, D.codigo as Codigo_Disc 
FROM pre_requisito
			INNER JOIN 
		disciplina D ON cod_disc = D.codigo
			INNER JOIN 
		disciplina P ON cod_pre = P.codigo;


--- QUESTÃO 4)
-- a)
SELECT P.nome, D.nome FROM professor P
INNER JOIN ensina E ON P.id = E.id_prof
INNER JOIN turma T ON E.id_turma = T.id
INNER JOIN disciplina D ON T.cod_disc = D.codigo;

SELECT P.nome, D.nome FROM professor P, ensina E, turma T, disciplina D
WHERE P.id = E.id_prof
 	AND E.id_turma = T.id
	AND T.cod_disc = D.codigo;

-- b)
SELECT P.nome, D.nome FROM professor P
INNER JOIN ensina E ON P.id = E.id_prof
INNER JOIN turma T ON E.id_turma = T.id
INNER JOIN disciplina D ON T.cod_disc = D.codigo
WHERE T.ano = 2023 AND T.semestre = 1;

-- c)
SELECT DISTINCT D.nome FROM disciplina D
INNER JOIN turma T ON D.codigo = T.cod_disc
INNER JOIN sala S ON T.predio_s = S.predio AND T.n_sala = S.numero
WHERE S.capacidade > 10;

-- d)
SELECT E.nome, F.nome, P.nome FROM estudante E
INNER JOIN faculdade F ON E.fac_est = F.sigla
INNER JOIN professor P ON P.id = E.tutor;

-- e)
SELECT * FROM turma T
LEFT JOIN sala S ON T.predio_s = S.predio AND T.n_sala = S.numero;

-- f)
ALTER TABLE professor
ADD data_nascimento DATE;

UPDATE professor
SET data_nascimento = (CURRENT_DATE - INTERVAL '70 years' + (random() * INTERVAL '30 years')::interval);

SELECT professor.nome AS Estudante, EXTRACT(YEAR FROM CURRENT_DATE) - EXTRACT(YEAR FROM estudante.datanasc) AS Idade_Est,
estudante.nome AS Professor, EXTRACT(YEAR FROM CURRENT_DATE) - EXTRACT(YEAR FROM professor.data_nascimento) AS Idade_Pro
FROM estudante
INNER JOIN professor ON EXTRACT(YEAR FROM estudante.datanasc) = EXTRACT(YEAR FROM professor.data_nascimento);

-- g)
SELECT professor.nome AS Estudante, EXTRACT(YEAR FROM CURRENT_DATE) - EXTRACT(YEAR FROM estudante.datanasc) AS est_idade,
estudante.nome AS Professor, EXTRACT(YEAR FROM CURRENT_DATE) - EXTRACT(YEAR FROM professor.data_nascimento) AS prof_idade
FROM estudante
INNER JOIN professor ON EXTRACT(YEAR FROM estudante.datanasc) != EXTRACT(YEAR FROM professor.data_nascimento);



--- QUESTÃO 5)
	-- a
SELECT D.nome as nome_disciplina, P.nome as nome_prereq 
FROM pre_requisito
			INNER JOIN 
		disciplina D ON cod_disc = D.codigo
			INNER JOIN 
		disciplina P ON cod_pre = P.codigo;
	-- b
SELECT D.nome as nome_disciplina, P.nome as nome_prereq 
FROM pre_requisito
			INNER JOIN 
		disciplina D ON cod_disc = D.codigo
			INNER JOIN 
		disciplina P ON cod_pre = P.codigo
WHERE D.ch > P.ch;
	-- c
INSERT INTO faculdade (sigla, nome, predio, orcamento) VALUES
('INFIS', 'Instituto de Física','1J',10000000),
('FACOM', 'Faculdade de Computação','1B',10000000),
('FAMAT', 'Faculdade de Matemática','1F',10000000); 

INSERT INTO disciplina(codigo, nome, fac_disc, ch) VALUES  
('FIS033', 'Física Moderna', 'INFIS', 60), 
('CAL002', 'Cálculo 2', 'FAMAT', 60), 
('ELT044', 'Programação Básica', 'FEELT', 60), 
('GBC099', 'Programação Avançada', 'FACOM', 90); 

INSERT INTO pre_requisito VALUES 
('FIS033', 'CAL002'),
('GBC099', 'ELT044');

SELECT D.nome as nome_disciplina, P.nome as nome_prereq 
FROM pre_requisito
			INNER JOIN 
		disciplina D ON cod_disc = D.codigo
			INNER JOIN 
		disciplina P ON cod_pre = P.codigo
WHERE D.fac_disc <> P.fac_disc;
	-- d 
SELECT E.nome as Aluno, F.nome as faculdade_aluno , P.nome as Tutor, FP.nome as faculdade_professor 
FROM estudante E
			INNER JOIN 
		professor P 
			INNER JOIN faculdade FP on P.fac_prof = FP.sigla
		ON E.tutor = P.id
			INNER JOIN
		faculdade F ON E.fac_est = F.sigla;
	-- e
SELECT E.nome as Aluno, F.nome as faculdade_aluno , P.nome as Tutor, FP.nome as faculdade_professor 
FROM estudante E
			INNER JOIN 
		professor P 
			INNER JOIN faculdade FP on P.fac_prof = FP.sigla
		ON E.tutor = P.id and E.fac_est <> P.fac_prof
			INNER JOIN
		faculdade F ON E.fac_est = F.sigla;
	-- f
INSERT INTO disciplina VALUES 
('ABC1','Programa Auditorial','FADIR',60),
('ABC2','Programação Lógica','FECIV',60),
('ABC3','Eletrodinâmica','FEELT',60);
INSERT INTO turma (id, turma, semestre, ano, cod_disc, predio_s, n_sala) VALUES 
  (9999, 'AA', 1, 2023, 'ABC1', '3Q', 306), 
  (9998, 'AB', 1, 2023, 'ABC1', '3Q', 306), 
  (9997, 'JJ', 1, 2023, 'ABC2', '3Q', 207), 
  (9996, 'KK', 1, 2023, 'ABC3', '3Q', 207), 
  (9995, 'DD', 1, 2023, 'ABC3', '3Q', 108); 
INSERT INTO frequenta(id_est, id_turma, nota) 
VALUES 
  ('1170', 9999, 75.0), 
  ('1171', 9998, 67.0), 
  ('1172', 9997, 99.0), 
  ('1173', 9996, 97.0), 
  ('1174', 9995, 64.0); 
  
SELECT e.nome as nome_aluno, fe.nome as faculdade_aluno, d.nome as disciplina, fd.nome as faculdade_disciplina
FROM estudante e, faculdade fe, faculdade fd, disciplina d, turma T, frequenta
WHERE
	fe.sigla <> fd.sigla
	AND T.id = id_turma AND e.id = id_est
	AND T.cod_disc = D.codigo
	AND fe.sigla = e.fac_est
	AND fd.sigla = d.fac_disc;

	-- g
SELECT E.id, E.nome, D.nome
FROM estudante E, disciplina D, frequenta, turma T
	WHERE 
		E.id = id_est
		AND T.id = id_turma 
		AND T.cod_disc = D.codigo;


--- QUESTÃO 6)
-- a)
SELECT P.nome AS nome_professor,E.nome AS nome_aluno FROM professor P
LEFT JOIN estudante E ON P.id = E.tutor;

-- b)
SELECT D1.nome, D2.nome FROM disciplina D1
LEFT JOIN pre_requisito PR ON D1.codigo = PR.cod_disc
LEFT JOIN disciplina D2 ON PR.cod_pre = D2.codigo;

-- c)
SELECT professor.nome AS nome_professor,
COALESCE(turma.turma || ', ' || turma.semestre || ', ' || turma.ano || ', ' || turma.cod_disc, '<professor sem disciplina>') AS turma
FROM professor
LEFT JOIN ensina ON professor.id = ensina.id_prof
LEFT JOIN turma ON ensina.id_turma = turma.id;

-- d)
SELECT D.nome FROM disciplina D
LEFT JOIN pre_requisito PR ON D.codigo = PR.cod_disc
WHERE PR.cod_pre IS NULL;

-- e)
SELECT E.nome AS nome_estudante
FROM estudante E
LEFT JOIN frequenta F ON E.id = F.id_est
WHERE F.id_turma IS NULL;

-- f)
INSERT INTO disciplina VALUES 
('ABC4','Programa Auditorial','FADIR',60),
('ABC5','Programação Lógica','FECIV',60),
('ABC6','Eletrodinâmica','FEELT',60);
INSERT INTO turma (id, turma, semestre, ano, cod_disc, predio_s, n_sala) VALUES 
  (9994, 'AA', 1, 2023, 'ABC4', '3Q', 306), 
  (9993, 'AB', 1, 2023, 'ABC4', '3Q', 306), 
  (9992, 'JJ', 1, 2023, 'ABC5', '3Q', 207), 
  (9991, 'KK', 1, 2023, 'ABC6', '3Q', 207), 
  (9990, 'DD', 1, 2023, 'ABC6', '3Q', 108);

INSERT INTO horario_aula VALUES
(2, 'f', 9994),
(2, 'g', 9994),
(5, 'f', 9993),
(5, 'g', 9993); 

SELECT T.* FROM turma T
LEFT JOIN horario_aula HA ON T.id = HA.id_turma
LEFT JOIN frequenta F ON T.id = F.id_turma
WHERE HA.id_sem IN ('2', '5')  
  AND F.id_turma IS NULL;  