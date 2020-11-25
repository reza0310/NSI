/*SELECT sum(population_2010) FROM communes

SELECT count(*) FROM communes WHERE num_departement = 44 

SELECT * FROM communes ORDER BY surface ASC LIMIT 10  #Corec: SELECT nom, bum_departement, surface FROM communes ORDER BY surface LIMIT 10

SELECT * FROM communes ORDER BY population_2010 DESC LIMIT 10

SELECT * FROM communes WHERE num_departement = 44 ORDER BY population_2010/surface DESC LIMIT 12

SELECT num_departement AS "Numéro de département", count(*) AS "Nombre de communes" FROM communes GROUP BY num_departement

SELECT num_departement, sum(population_2010) FROM communes GROUP BY num_departement HAVING sum(population_2010)>1000000 ORDER BY sum(population_2010) DESC

SELECT *, num_departement=44 AS "En Loire-Atlantique", num_departement=49 AS "En Maine-et-Loire" FROM communes WHERE nom LIKE '%a%' AND nom LIKE '%e%' AND nom LIKE '%i%' AND nom LIKE '%o%' AND nom LIKE '%u%' AND nom LIKE '%y%' ORDER BY LENGTH(nom) ASC
SELECT sum(num_departement=44) AS "Nombre en Loire-Atlantique", sum(num_departement=49) AS "Nombre en Maine-et-Loire" FROM communes WHERE nom LIKE '%a%' AND nom LIKE '%e%' AND nom LIKE '%i%' AND nom LIKE '%o%' AND nom LIKE '%u%' AND nom LIKE '%y%'

SELECT * FROM communes WHERE zmax IS NOT NULL AND zmin IS NOT NULL ORDER BY zmax-zmin DESC LIMIT 15

SELECT *, population_2010-population_1999 AS "Augmentation (nombre)", population_2010/population_1999 AS "Augmentation (rapport)", 1.0*population_2010/population_1999 AS "Augmentation (rapport en flottant)" FROM communes WHERE num_departement=44 ORDER BY population_2010-population_1999 DESC LIMIT 10

SELECT *, population_2010-population_1999 AS "Augmentation (nombre)", population_2010/population_1999 AS "Augmentation (rapport)", 1.0*population_2010/population_1999 AS "Augmentation (rapport en flottant)" FROM communes WHERE num_departement=44 ORDER BY 1.0*population_2010/population_1999 DESC LIMIT 10*/