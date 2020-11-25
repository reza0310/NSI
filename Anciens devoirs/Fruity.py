import matplotlib.pyplot as plt
import pandas as pd

fruits = pd.read_csv("fruits.csv")

apple_data = fruits[fruits['fruit_name']=="apple"]
orange_data = fruits[fruits['fruit_name']=="orange"]
lemon_data = fruits[fruits['fruit_name']=="lemon"]

plt.title("Représentation des données")

pommes = False
oranges = False
citrons = False

for pomme in apple_data["fruit_label"]:
    if not pommes:
        plt.scatter(apple_data['width'], apple_data['height'], c="red", label="Pommes")
        pommes = True
    else:
        plt.scatter(apple_data['width'], apple_data['height'], c="red")

for orange in orange_data["fruit_label"]:
    if not oranges:
        plt.scatter(orange_data['width'], orange_data['height'], c="orange", label="Oranges")
        oranges = True
    else:
        plt.scatter(orange_data['width'], orange_data['height'], c="orange")

for citron in lemon_data["fruit_label"]:
    if not citrons:
        plt.scatter(lemon_data['width'], lemon_data['height'], c="yellow", label="Citrons")
        citrons = True
    else:
        plt.scatter(lemon_data['width'], lemon_data['height'], c="yellow")

plt.scatter(6.3, 8, c="green", label="Pourri")

plt.legend()
plt.xlabel('Largeur')
plt.ylabel('Hauteur')
plt.show()