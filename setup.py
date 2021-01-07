from distutils.core import setup, Extension

module = Extension('arbres', sources=['module.cpp'], libraries=["user32", "gdi32"])

setup(name='arbres',
    version='1.0',
    description="Module d'affichage d'arbres",
    long_description="Module permettant d'afficher à l'écran un signe, un chiffre, d'obtenir la taille de l'écran, de faire un cercle ou un trait.",
    author="reza0310",
    author_email="reza031077@yahoo.fr",
    ext_modules=[module])