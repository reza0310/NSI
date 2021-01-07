SELECT * FROM departements JOIN regions ON departements.num_region = regions.num_region WHERE regions.nom = "Bretagne" OR departements.nom = "Pays de la Loire"
