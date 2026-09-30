GUIDE D'ÉTUDE : MODULE 06 - C++ CASTS & CONVERSIONS
I. NOUVELLE MATIÈRE À APPRENDRE : LES CASTS EN C++98

Contrairement au C où l'on utilisait souvent des casts implicites ou le style (type)variable, le C++ introduit des opérateurs de conversion explicites pour garantir la sécurité et la clarté du code. Dans ce module (standard C++98), vous devez maîtriser quatre types de conversions spécifiques :

    static_cast<type>(expression)
        Usage : Conversions liées au typage statique.
        Cas d'usage : Conversion entre types numériques (int vers float, double vers int), conversion entre pointeurs de classes parentes et enfants (dans une hiérarchie polymorphe, mais sans vérification dynamique), ou conversion vers void*.
        Risque : Il ne fait aucune vérification à l'exécution. Si vous convertissez un entier trop grand pour un char, le résultat est défini par la machine mais peut être inattendu.

    dynamic_cast<type>(expression)
        Usage : Conversions sûres dans une hiérarchie polymorphe.
        Condition préalable : La classe de base doit avoir au moins un membre virtuel (généralement un destructeur virtuel).
        Comportement : Vérifie à l'exécution si l'objet pointe réellement vers le type cible.
            Pour les pointeurs : Retourne nullptr si l'échec.
            Pour les références : Lance une exception std::bad_cast si l'échec.
        Contexte du module : Utilisé dans l'Exercice 02 pour identifier le type réel d'un objet dérivé (A, B, C) héritant de Base sans utiliser <typeinfo>.

    const_cast<type>(expression)
        Usage : Modification des attributs const ou volatile.
        Fonction : Ajoute ou retire la qualification const.
        Attention : Ne jamais modifier une variable const réelle via ce cast, c'est un comportement indéfini. On l'utilise souvent pour appeler des fonctions anciennes qui prennent des char* non-const alors qu'on a un const char*.

    reinterpret_cast<type>(expression)
        Usage : Réinterprétation purement binaire du contenu mémoire.
        Fonction : Convertit n'importe quel pointeur en n'importe quel autre type de pointeur, ou entiers en pointeurs.
        Danger : Très peu sûr, dépend de l'architecture.
        Contexte du module : Utilisé dans l'Exercice 01 pour sérialiser un pointeur en entier (uintptr_t) et vice-versa. C'est l'outil pour "cacher" une adresse dans un nombre.

    Conversion implicite vs Explicite
        Le C++98 permet encore beaucoup de conversions implicites (ex: int vers float).
        Cependant, pour ce module, il est impératif d'utiliser les syntaxes ci-dessus plutôt que le vieux style C (type)val.

II. DÉFINITIONS CLÉS

    Orthodox Canonical Form : Une structure standard pour les classes en C++ incluant :
        Constructeur par défaut.
        Constructeur de copie.
        Opérateur d'affectation (operator=).
        Destructeur.
        (Souvent) Constructeur paramétré et opérateur ==.
        Note : Les exercices 00 et 01 demandent cette forme stricte, sauf mention contraire.
    Polymorphisme : Capacité d'un objet à prendre plusieurs formes (ici, pointer vers Base mais contenir un objet A, B ou C).
    Destructeur Virtuel : Fonction appelée lors de la suppression d'un objet via un pointeur de type base. Essentiel pour éviter les fuites de mémoire et s'assurer que le bon destructeur (dérivé) est appelé.
    Serialize/Deserialize : Transformer un objet complexe en une suite d'octets (ou ici, un entier) pour le stocker/transmettre, puis reconstruire l'objet original.
    Non-displayable character : Caractère ASCII dont la valeur ne correspond pas à un caractère imprimable (généralement < 32 ou > 126).

III. EXPLICATIONS COMPLETES EN PROFONDEUR PAR EXERCICE
EXERCICE 00 : Conversion de types scalaires (ScalarConverter)

Objectif : Créer une classe statique capable d'analyser une chaîne de caractères (string) et de déterminer si elle représente un char, int, float ou double, puis d'afficher les conversions.

Logique de résolution :

    Structure de la classe :
        Pas de constructeurs privés/publics (classe non instanciable).
        Méthode unique static void convert(std::string const& str).
        Doit gérer les erreurs (overflow, format invalide).

    Détection du type d'entrée :
        Vous devez écrire une fonction utilitaire (ou intégrer la logique dans convert) pour analyser la chaîne str.
        Critères :
            Contient-il un point décimal . ou un exposant f ? -> Probablement Float/Double.
            Est-ce un seul caractère entouré de ' ? -> Char.
            Contient-il -inf, +inf, nan ? -> Cas spéciaux.
            Sinon, essayez de parser comme Int.

    Gestion des cas particuliers :
        NaN / Inf : Le C++ gère ces valeurs via <cmath> ou <limits>. Attention aux suffixes f pour float/double.
        Overflow : Utilisez <limits> pour vérifier si la valeur dépasse INT_MAX, INT_MIN, etc.
        Char non displayable : Si la valeur numérique du char est hors de l'imprimable, affichez "Non displayable".

    Les Casts à utiliser :
        Pour passer de string à double : atof() ou strtod().
        Pour passer de double à int : static_cast<int>(val).
        Pour passer de double à char : static_cast<char>(val).
        Interdit : Utilisation de printf avec des formats variés pour tout faire d'un coup, vous devez traiter chaque type séparément pour contrôler le message d'erreur.

Pièges fréquents :

    Oublier de vérifier si la chaîne est vide.
    Ne pas gérer le cas où une entrée valide pour int devient impossible pour char (ex: 1000).
    Confusion entre float et double (suffixe f).

EXERCICE 01 : Sérialisation (Serializer)

Objectif : Implémenter une classe Serializer avec deux méthodes statiques pour convertir un pointeur Data* en uintptr_t et inversement.

Logique de résolution :

    La classe Data :
        Créez une structure Data avec au moins un membre (ex: int value;).
        Elle doit respecter la forme canonique si demandé, mais ici l'accent est sur la manipulation de pointeurs.

    La méthode serialize :
        Prend Data* ptr.
        Doit retourner uintptr_t.
        Le Cast : Utilisez reinterpret_cast<uintptr_t>(ptr). Cela transforme l'adresse mémoire en un nombre entier sans changer les bits de l'adresse.
        Pourquoi pas static_cast ? Parce que static_cast ne permet pas de convertir arbitrairement un pointeur vers un entier. Seul reinterpret_cast le permet.

    La méthode deserialize :
        Prend uintptr_t raw.
        Doit retourner Data*.
        Le Cast : Utilisez reinterpret_cast<Data*>(raw). Cela prend le nombre et le réinterprète comme une adresse mémoire.

    Test :
        Allouer un Data, appeler serialize, récupérer l'entier, appeler deserialize, et vérifier que le nouveau pointeur pointe bien vers le même endroit (comparaison ==).

Point clé pédagogique : Comprendre que uintptr_t est simplement un conteneur pour l'adresse. Ce n'est pas une transformation de données, c'est une manipulation d'adresses brutes.
EXERCICE 02 : Identifier le vrai type (Identify real type)

Objectif : Déterminer dynamiquement si un objet pointé par Base* est en réalité de type A, B ou C, sans utiliser <typeinfo>.

Logique de résolution :

    Architecture des classes :
        Base : Doit avoir un destructeur virtuel (pour permettre le polymorphisme correct).
        A, B, C : Héritent publiquement de Base.

    Fonction generate :
        Retourne Base* pointant aléatoirement vers un nouvel objet A, B ou C.
        Utilisez rand() pour choisir.

    Fonction identify(Base* p) :
        Accepte un pointeur.
        Solution : Utilisez dynamic_cast<A*>(p).
            Si le résultat n'est pas nullptr, l'objet est de type A.
            Sinon, essayez dynamic_cast<B*>(p).
            Sinon, c'est C.
        Pourquoi dynamic_cast ? Car c'est le seul moyen sûr de remonter la hiérarchie polymorphe sans connaître le type exact à la compilation.

    Fonction identify(Base& p) :
        Accepte une référence.
        Contrainte interdite : Interdiction d'utiliser un pointeur interne.
        Solution : Utilisez dynamic_cast<A&>(p).
            Si ça lance std::bad_cast, essayez B, puis C.
            Vous devez attraper l'exception avec un bloc try...catch.

Pièges fréquents :

    Oublier le destructeur virtuel dans Base. Sans lui, dynamic_cast ne fonctionne pas (le compilateur refuse ou le comportement est indéfini).
    Tenter d'utiliser typeid (interdit par l'énoncé).
    Ne pas gérer l'exception bad_cast dans la version référence.

IV. ÉTAPES POUR RÉALISER LES EXOS (PROCÉDURE)

Suivez cet ordre rigoureux pour chaque exercice :

    Préparation de l'environnement :
        Créez le dossier exXX (ex: ex00).
        Créez la structure de fichiers : Makefile, main.cpp, NomClasse.hpp, NomClasse.cpp.
        Configurez le Makefile avec les flags obligatoires : -Wall -Wextra -Werror -std=c++98.

    Analyse de l'énoncé :
        Lisez les contraintes (interdits, autorisations).
        Notez les noms exacts des classes et méthodes.

    Implémentation du squelette :
        Définissez les classes dans les headers avec les include guards (#ifndef ... #define ... #endif).
        Respectez la forme canonique si requis.

    Implémentation de la logique métier :
        Écrivez le code de conversion ou de sérialisation.
        Appliquez les bons casts (static_cast, reinterpret_cast, etc.).
        Gérez les erreurs (overflow, types invalides).

    Création du programme de test (main.cpp) :
        Testez tous les cas limites (zéro, négatif, infini, NaN, overflow).
        Affichez les résultats exactement comme demandé dans l'exemple.

    Compilation et Debugging :
        Compilez avec make.
        Corrigez les warnings (car -Werror transforme les warnings en erreurs).
        Assurez-vous que le code respecte le standard C++98 (pas de auto, pas de lambdas, pas de STL containers).

    Revue de conformité :
        Avez-vous utilisé using namespace std ? (Interdit).
        Avez-vous inclus toutes les dépendances dans les headers ?
        Y a-t-il des fuites de mémoire (si utilisation de new) ?

V. RÈGLES DE FORMATTAGE ET SOUMISSION

    Nommage : ex00, ex01, ex02. Fichiers : ClassName.hpp, ClassName.cpp.
    Style : Pas de Norminette C++, mais code propre et lisible.
    Interdits absolus :
        Bibliothèques externes (Boost, C++11+).
        printf, malloc, free.
        using namespace std.
        Fonctions implémentées dans les headers (sauf templates).
        STL (vector, map, algorithm) avant le Module 08.
    Makefile : Doit comprendre les cibles all, re, clean, fclean.

Ce guide couvre l'ensemble des concepts théoriques et pratiques nécessaires pour réussir le Module 06. La clé du succès réside dans la compréhension fine de la différence entre les types de casts et la rigueur dans le respect des règles C++98 strictes. Bonne programmation !
