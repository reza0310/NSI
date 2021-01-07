SELECT * FROM departements JOIN regions ON departements.num_region = regions.num_region WHERE regions.nom = "Bretagne" OR departements.nom = "Pays de la Loire"
SELECT count(*) as "Nombre de communes", departements.nom FROM communes JOIN departements ON departements.num_departement = communes.num_departement GROUP BY communes.num_departement ORDER BY population_2010 DESC
