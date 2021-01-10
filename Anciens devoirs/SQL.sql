SELECT * FROM departements JOIN regions ON departements.num_region = regions.num_region WHERE regions.nom = "Bretagne" OR departements.nom = "Pays de la Loire"
SELECT count(*) as "Nombre de communes", departements.nom, sum(population_2010) FROM communes JOIN departements ON departements.num_departement = communes.num_departement GROUP BY communes.num_departement ORDER BY sum(population_2010) DESC 
SELECT regions.nom, AVG(communes.population_2010/communes.surface) as "densité" FROM regions JOIN communes JOIN departements ON regions.num_region = departements.num_region AND departements.num_departement = communes.num_departement GROUP BY regions.nom   //remplacer AVG(communes.population_2010/communes.surface) par sum(communes.population_2010)/sum(communes.surface)
SELECT DISTINCT departements.nom FROM departements JOIN communes ON departements.num_departement = communes.num_departement WHERE communes.nom LIKE "Petit%"

SELECT * FROM communes WHERE population_2010 > 100*(SELECT avg(population_2010) FROM communes)
SELECT nom FROM communes WHERE zmin > 940 OR zmin = 940 ORDER BY zmin ASC LIMIT 2
