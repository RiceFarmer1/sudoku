/* 
Author: Oscar Pang

Purpose: First, a random English word with a length of 9 and has only non-repeating letters will be generated from a list. Then, a sudoku board would be created based on 
the letters in the word. The objective is to fill this board completely so that each column, row, and 3x3 grids contain unique letters. After a board has been generated 
and displayed, the user will be prompted with a question of whether they want to continue, get a hint, give up, or quit the entire game. If the user chooses to continue, 
they will be prompted to enter a position to insert a letter and the letter to be inserted. If the user chooses to get a hint (there will be 10 hints max), a hint will be 
displayed onto the sudoku board. If the user chooses to give up, the solution will be displayed and a new game will begin. If the user chooses to quit, the entire program 
will stop. The same process will then be repeated, starting with a new word being generated. When the user quits, statistics will be displayed on how many times the user was 
successful or unsuccessful.
 
Status: DONE 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A list of all 1140 words that are 9 letters long and have no repeating letters
const char const *words_list[1141] = { "abducting", "abduction", "abjection", "abolished", "abruption", "absconder", "absolving", "absurdity", "abusively", "acidulent", 
"adjunctly", "adjusting", "adjustive", "admixture", "adoringly", "adsorbent", "adsorbing", "advection", "adversity", "adverting", "afterglow", "aitchbone", "alchemist", 
"algorithm", "almsgiver", "alongside", "amblyopic", "ambushing", "ametropic", "amortized", "amphibole", "amplitude", "amusingly", "anchorite", "angelfish", "angleworm", 
"anguished", "anhydrite", "ankylosed", "ankylotic", "anthropic", "antiserum", "anxiously", "aphorized", "archfiend", "artichoke", "arytenoid", "asyndetic", "atrophied", 
"auctioned", "authoring", "authorize", "autogenic", "avirulent", "awestruck", "backfield", "backfired", "backslide", "backswept", "backsword", "bacterium", "bacteroid", 
"balconied", "bandolier", "baronetcy", "basketful", "bastioned", "batfowled", "bearishly", "becalming", "bedspring", "befouling", "beholding", "bemocking", "benchmark", 
"bestowing", "betraying", "bewraying", "bifurcate", "bigotedly", "bimonthly", "binocular", "biography", "birdhouse", "blackfish", "blasphemy", "bleaching", "blindworm", 
"blockader", "blockhead", "blockiest", "blotchier", "blotching", "blowziest", "bluepoint", "blueprint", "boardlike", "botanized", "bothering", "boulevard", "bowstring", 
"boyfriend", "bracingly", "branchlet", "brawniest", "breaching", "breakdown", "breasting", "breathing", "brimstone", "broaching", "brocading", "bromating", "brominate", 
"bronchial", "brutalize", "brutishly", "bucketing", "buckthorn", "buckwheat", "budgetary", "bulwarked", "bumpering", "bumpkinly", "bunchiest", "burnished", "busheling", 
"butcherly", "byproduct", "bystander", "cabinetry", "cabriolet", "cadetship", "cambering", "caponized", "caprioled", "capsuling", "capsulize", "captioned", "capturing", 
"carbonize", "carousing", "carpeting", "casketing", "cautioned", "cavorting", "censorial", "centigram", "certainly", "chagrined", "chalkiest", "chamoised", "chandlery", 
"changeful", "charwomen", "chelating", "chelation", "chemisorb", "chemistry", "cherimoya", "chipboard", "chlordane", "chondrite", "chondrule", "chortling", "chorusing", 
"chromatid", "chromatin", "chunkiest", "clamoring", "clampdown", "clangored", "clavering", "clepsydra", "clergyman", "clerkship", "clipboard", "closeting", "closuring", 
"cloturing", "cloudiest", "coastline", "cogitable", "cohabited", "coinsured", "colanders", "columbine", "columnist", "combating", "combative", "combusted", "comparing", 
"comparted", "compendia", "compering", "competing", "complaint", "compliant", "complying", "comprised", "computing", "comradely", "configure", "confirmed", "confiture", 
"conflated", "congruity", "conjugate", "conspired", "constable", "construed", "consulate", "consulted", "contrived", "contumely", "convexity", "convulsed", "copulated", 
"copyright", "corbeling", "cornfield", "cornflake", "corpulent", "coshering", "costively", "costumier", "costuming", "countable", "countably", "courtesan", "courtship", 
"craftsmen", "crankiest", "crawliest", "credulity", "cremating", "cremation", "crimsoned", "croupiest", "crumbiest", "crumbling", "crumpling", "crusading", "cryptogam", 
"culminate", "cumbering", "cuneiform", "curbstone", "cursively", "curtailed", "curtained", "curtsying", "curveting", "cushioned", "cuspidate", "custodial", "custodian", 
"customary", "customize", "cymbalist", "cytoplasm", "dangerous", "dashingly", "davenport", "dayflower", "deathblow", "debarking", "decamping", "decathlon", "declaring", 
"declawing", "defiantly", "definably", "deflating", "deflation", "defoliant", "deforming", "deformity", "defraying", "delousing", "demonical", "departing", "deploring", 
"deploying", "depluming", "deporting", "depraving", "depravity", "desalting", "descrying", "desirably", "desultory", "detaching", "detouring", "devaluing", "deviously", 
"devouring", "diathermy", "diplomacy", "discharge", "discovery", "disembark", "dishtowel", "dishwater", "dislocate", "dismantle", "dithyramb", "docketing", "doctrinal", 
"dogmatize", "dosimetry", "doughiest", "doughtier", "doughtily", "dowitcher", "downright", "downscale", "downshift", "downstage", "draftsmen", "dragonfly", "drawknife", 
"drinkable", "dropsical", "drumstick", "duplexing", "duplicate", "dynamiter", "dysphoria", "dysphoric", "dystopian", "earthling", "eastbound", "ectoplasm", "educating", 
"education", "eightfold", "embarking", "embodying", "embracing", "embryonal", "embryonic", "employing", "emulating", "emulation", "endoplasm", "endurably", "enviously", 
"enzymatic", "equitably", "equivocal", "escorting", "estimably", "ethmoidal", "eucalypti", "eurythmic", "excluding", "exclusion", "excursion", "excusably", "exhorting", 
"expiatory", "exploding", "exploring", "exporting", "expulsion", "extruding", "extrusion", "exudation", "factoring", "factorize", "faltering", "fancywork", "farmhouse", 
"fashioned", "fashioner", "fathering", "fathoming", "featuring", "fecundity", "feudalism", "feudalist", "feudality", "feudatory", "fieldwork", "firsthand", "fisherman", 
"fishplate", "flagstone", "flashcube", "flavoring", "flowchart", "flowering", "flybridge", "flyweight", "focalized", "foreshank", "foresight", "foresting", "formality", 
"formalize", "formative", "formulaic", "formulate", "fornicate", "forsaking", "forsythia", "fostering", "framboise", "franchise", "frangible", "freckling", "frescoing", 
"frolicked", "frowziest", "frugality", "fruitcake", "frumpiest", "fruticose", "fulminate", "fumigated", "fumigator", "furbished", "furcation", "furnished", "furtively", 
"galumphed", "garnished", "gasholder", "gearshift", "genocidal", "genotypic", "gerfalcon", "ghastlier", "ghostlike", "girandole", "glamorize", "globefish", "glucoside", 
"glutamine", "glycoside", "gnarliest", "godfather", "godparent", "goldbrick", "goldfinch", "goldsmith", "grandiose", "grapeshot", "graticule", "greyhound", "grouchily", 
"groundsel", "grubstake", "grumpiest", "guardsmen", "guidepost", "gunpowder", "gymnastic", "gynoecium", "gyrfalcon", "hailstone", "hailstorm", "hairstyle", "haltering", 
"hampering", "hamstring", "hamstrung", "handiwork", "handsomer", "handspike", "handwrite", "handwrote", "harlequin", "harmonize", "havocking", "headfirst", "heartsick", 
"hectogram", "hectoring", "heinously", "hemolytic", "heralding", "herbalist", "hesitancy", "hideously", "histogram", "hobnailed", "horseback", "horsemint", "horseplay", 
"horsetail", "housemaid", "humanized", "humanlike", "humdinger", "hungriest", "husbandly", "husbandry", "hydrating", "hydration", "hydraulic", "hyperbola", "hypnotism", 
"hypnotize", "hypocrite", "ibuprofen", "ideograph", "implanted", "importune", "imposture", "impotency", "imprudent", "imputable", "inclosure", "incrusted", "incubated", 
"incubator", "inculpate", "incurable", "incurably", "incurvate", "indecorum", "inexactly", "infracted", "ingrafted", "inoculate", "inspector", "insulated", "insulator", 
"insurable", "interlock", "interplay", "introduce", "involucre", "involuted", "irksomely", "jacketing", "jackfruit", "jacklight", "jacksmelt", "jailhouse", "jockeying", 
"jockstrap", "jocundity", "jubilance", "jubilated", "judgeship", "jungliest", "juxtapose", "kilohertz", "knavishly", "koshering", "kymograph", "labyrinth", "lackeying", 
"lakefront", "langouste", "larcenist", "lathering", "lawyering", "layperson", "lecturing", "legionary", "lethargic", "lifeguard", "ligatured", "lightface", "lightsome", 
"livestock", "locksmith", "logarithm", "longevity", "longitude", "loquacity", "lubricant", "lubricate", "lucrative", "lumbering", "lunchtime", "lustering", "lymphatic", 
"machinery", "macintosh", "magnitude", "mahlstick", "makeshift", "manicured", "manifesto", "manticore", "marketing", "marveling", "masculine", "masterful", "mastering", 
"maulstick", "mawkishly", "mayflower", "measuring", "mechanist", "mendacity", "menstrual", "metabolic", "metalwork", "micropyle", "microwave", "miscreant", "miserably", 
"misgovern", "mishandle", "misplaced", "misplayed", "misquoted", "misreckon", "mockingly", "modernist", "modernity", "moldering", "molesting", "monastery", "moralized", 
"mordantly", "morganite", "morseling", "mothering", "mountable", "mousetrap", "moustache", "muscadine", "mustached", "mustachio", "mustering", "neighbors", "nailbrush", 
"narcotize", "naughtier", "naughtily", "nemophila", "nervously", "neuralgic", "neuroglia", "nightclub", "nightmare", "normality", "normalize", "normative", "nostalgic", 
"notarized", "nourished", "numerical", "nursemaid", "nymphalid", "numerical", "obfuscate", "objecting", "objurgate", "obligated", "obscenity", "obscurant", "obscurely", 
"obscuring", "obscurity", "observant", "observing", "obstinacy", "obtruding", "obtrusive", "odalisque", "oligarchy", "onslaught", "operantly", "operating", "organized", 
"osculated", "ostracize", "outbraved", "outcrying", "outfacing", "outlander", "outlawing", "outlaying", "outpacing", "outplayed", "outracing", "outranged", "outranked", 
"outsailed", "outspread", "outwalked", "outwardly", "ovalbumin", "overawing", "overbuild", "overbuilt", "overhasty", "overlying", "overmatch", "overnight", "oversight", 
"overusing", "ovulating", "ownership", "pachyderm", "packeting", "packhorse", "paintwork", "palmistry", "paltering", "panegyric", "pantheism", "pantyhose", "parboiled", 
"parceling", "parchment", "parhelion", "parleying", "parodying", "parsimony", "pasturing", "patchouli", "patchouly", "patchwork", "patrimony", "patrolmen", "patronize", 
"paunchier", "peculator", "pecuniary", "penultima", "perfuming", "perfusion", "permuting", "personify", "pervading", "pervasion", "phagocyte", "philander", "piquantly", 
"piscatory", "pitchfork", "piteously", "planetoid", "playhouse", "plaything", "pleaching", "plethoric", "plowshare", "pluckiest", "pneumatic", "pocketful", "pocketing", 
"pointedly", "polarized", "policeman", "polyamide", "polyhedra", "polymeric", "porcelain", "postfixed", "posturing", "poulticed", "powdering", "preachify", "preachily", 
"preaching", "predacity", "predating", "predation", "prefacing", "preluding", "presuming", "princedom", "printable", "privately", "probating", "probative", "producing", 
"profanely", "profanity", "profusely", "progestin", "provident", "proximate", "prudently", "prudishly", "pseudonym", "pterygium", "pterygoid", "published", "publisher", 
"puckering", "puckishly", "pugnacity", "pulmonary", "pulsating", "pulsation", "punchiest", "purchased", "purgation", "purgative", "purloined", "purveying", "pyridoxal", 
"quavering", "quicksand", "quickstep", "quodlibet", "randomize", "raspingly", "raunchily", "recasting", "recopying", "recouping", "redacting", "redaction", "redisplay", 
"reducibly", "reduction", "refashion", "reflating", "reflation", "refutably", "rehousing", "relapsing", "reloading", "remindful", "remolding", "removably", "repasting", 
"replacing", "replaying", "republish", "repulsing", "repulsion", "reputably", "resolving", "restyling", "resulting", "revaluing", "revamping", "revolting", "revulsion", 
"rhapsodic", "rheumatic", "rocketing", "roguishly", "roqueting", "roughcast", "roughneck", "roundelay", "rousingly", "routinely", "ruminated", "salubrity", "sapiently", 
"schmaltzy", "schnauzer", "schnitzel", "schnorkel", "sclerotia", "scoundrel", "scrambled", "scrawling", "screaming", "scrounged", "scrupling", "sculpting", "searching", 
"seaworthy", "secluding", "secondary", "sectional", "sectorial", "sectoring", "seduction", "semilunar", "sequacity", "sexuality", "shackling", "shadowily", "shadowing", 
"shakedown", "shambling", "shipboard", "shipowner", "shipwreck", "shockable", "shoeblack", "shortcake", "shortwave", "shoveling", "showering", "showplace", "shrinkage", 
"shrouding", "sidetrack", "signatory", "signature", "signboard", "simpleton", "simulated", "simulator", "skeptical", "sketchily", "sketching", "slaughter", "sleuthing", 
"slipcover", "slouchier", "slouching", "sluiceway", "snakebird", "snowdrift", "snowfield", "snowflake", "sobriquet", "socketing", "soldering", "solemnity", "solvating", 
"something", "soundable", "southerly", "southland", "southward", "spackling", "spadework", "sparingly", "sparkling", "spearmint", "specialty", "speckling", "spermatic", 
"spermatid", "spherical", "sphincter", "spikenard", "splintery", "splotched", "sprawling", "spreading", "sprightly", "springbok", "sprinkled", "sprouting", "squawking", 
"squeaking", "squealing", "squinched", "staghound", "starchily", "starching", "stauncher", "staunchly", "steadying", "stepchild", "stockpile", "stockyard", "stomached", 
"stomacher", "strangely", "strangled", "streaking", "streaming", "stridency", "strobilae", "stumbling", "subacidly", "subagency", "subalpine", "subaltern", "subatomic", 
"subdeacon", "subeditor", "subfamily", "subjacent", "subjoined", "sublimate", "submarine", "submicron", "subnormal", "subregion", "subtropic", "subwaying", "suctioned", 
"suctorial", "sulfating", "sulfonate", "sunbathed", "sunbather", "sunflower", "supernova", "supinated", "supremacy", "surcingle", "surfacing", "surveying", "switchman", 
"switchmen", "swordplay", "swordtail", "sycophant", "symboling", "symbolize", "sympatric", "symphonic", "syncopate", "syndicate", "synodical", "tampering", "tarnished", 
"taxidermy", "teasingly", "tediously", "therapsid", "thinkable", "thinkably", "threadfin", "threading", "throwback", "thumbnail", "thwacking", "thylacine", "thyroidal", 
"thyroxine", "tinderbox", "touchable", "traducing", "trampling", "transduce", "trapezium", "trapezoid", "traveling", "treadling", "trembling", "tribesman", "triumphal", 
"triumphed", "troubling", "troweling", "truckling", "truckload", "trunkfish", "tuckering", "unblocked", "uncharged", "uncharted", "unclaimed", "unclasped", "uncloaked", 
"unclothed", "undercoat", "underplay", "underplot", "undershot", "unearthly", "unethical", "unfrocked", "unholiest", "uniformed", "uniformly", "universal", "unlatched", 
"unmatched", "unmixable", "unmovable", "unpoliced", "unreality", "unridable", "unrivaled", "unscathed", "unshackle", "unshapely", "unsighted", "unsightly", "unspoiled", 
"unsprayed", "untypical", "unwariest", "unwarlike", "upholding", "upholster", "uploading", "uprightly", "upscaling", "urbanized", "vainglory", "valorized", "vaporized", 
"variously", "varnished", "vectorial", "vectoring", "vehicular", "verbosity", "verdantly", "veritably", "vesicular", "vestryman", "vetchling", "vibrantly", "victualed",
"victualer", "virulency", "viscounty", "vocalized", "vocalizer", "volcanism", "voluntary", "vouchsafe", "voyeurism", "vulcanism", "vulcanize", "vulgarism", "vulgarity", 
"vulgarize", "waterbuck", "welcoming", "welfarist", "westbound", "windbreak", "windstorm", "winsomely", "wolfsbane", "womanized", "womanlike", "wonderful", "wordplays", 
"wordsmith", "workbench", "workplace", "worktable", "worshiped", "wreathing", "wrestling", "wristband", "yachtsmen", "yardstick", "youngster", "zygomatic" };

// Here a random solved numerical sudoku board I found on this website: https://sandiway.arizona.edu/sudoku/examples.htm; it will used later to generate a word sudoku board
const int number_sudoku[9][9] = { 1, 5, 2,   4, 8, 9,   3, 7, 6,
				  7, 3, 9,   2, 5, 6,   8, 4, 1,
				  4, 6, 8,   3, 7, 1,   2, 9, 5,
				 
				  3, 8, 7,   1, 2, 4,   6, 5, 9,
				  5, 9, 1,   7, 6, 3,   4, 2, 8,
				  2, 4, 6,   8, 9, 5,   7, 1, 3,
				 
				  9, 1, 4,   6, 3, 7,   5, 8, 2,
				  6, 2, 5,   9, 4, 8,   1, 3, 7,
				  8, 7, 3,   5, 1, 2,   9, 6, 4 };

/* 
Purpose: To display the instructions of the game for the user.
Parameters: None
Returns: None
Side Effects: None
*/
void print_instructions() {
	printf("\n\n--------------------------------------------------------------------------------");
	printf("\n\nWelcome to the Word Sudoku game!");
	printf("\n\nHere are the instructions:");
	printf("\n\n1. First, a random 9 letter word with no repeating letters will be generated to form a Word Sudoku board.");
	printf("\n\n2. Then, you will be prompted for positions to insert letters and the letters themselves, until you solve the sudoku.");
	printf("\n\n3. In addition, you have the option to get at most 10 hints for each sudoku puzzle if you are stuck.");
	printf("\n\n4. However, feel free to give up if you don't want to continue trying. If you give up, the solution will be shown.\n");
}

/* 
Purpose: To generate a random word from a list of 1140 words and return it.
Parameters: None
Returns: The randomly generated word.
Side Effects: None
*/
char *generate_word() {
	// Generate a random index from "word_list"
	int index = rand() % 1140;
	// Return the word at that specific index
	return (char*) words_list[index];
}

/* 
Purpose: To generate a board based on the letters in the randomly generated word (store the board in "solved_board" and "modified_board").
Parameters: solved_board - the original (solved) board generated that will never be changed until a new word is generated.
			modified_board - the board that is originally the same as "solved_board" but will get updated as the user modifies it.
			hidden_letters - the parray that stores the hidden letters from the "solved_board".
			word - the randomly generated word.
Returns: None
Side Effects: None
*/
void generate_board(char solved_board[9][9], char modified_board[9][9], char hidden_letters[9][9], char* word) {

	// Looping variables to use while going through a 2D array
	int row = 0; 
	int col = 0;
	// Lopping varaible to use while going through the char array "word"
	int index = 0;
    // "word" randomized by swapping letters
	char randomized_word[10]; // add one extra space for the null character
	// To be used for swapping letters when randomizing the "word"
	int swap_index = 0;
	// To be used for swapping letters when randomizing the "word"
	char temp = 0;
	// To be used for generating a random row number
	int random_row_number = 0;
	// To be used for generating a random column number
	int random_col_number = 0;
	// For this game, the number of positions hidden to the user every time is randomized (18 to 36 positions hidden)
	int positions_to_hide = rand() % 19 + 18;

	// Inform the user about how many clues they have
	printf("\n\nYou get %d clues for this puzzle:", 81 - positions_to_hide);


	/* Now, it is time to generate the actual sudoku board based on the "word" in 3 steps */

	// Step 1: Randomize the word passed in as the parameter

	// Set the "randomized_word" to be equal to the "word" first
	for (index = 0; index < 9; index++) {
		randomized_word[index] = word[index];
 	}

	// Get a random index and swap the letter at that index with the letter at "randomized_word[index]" (repeat 9 times)
	for (index = 0; index < 9; index++) {
		swap_index = rand() % 9; 
		temp = randomized_word[swap_index];
		randomized_word[swap_index] = randomized_word[index];
		randomized_word[index] = temp;
	}

	// Step 2: Create a random sudoku board based on the 2D int array "number_sudoku" declared at the start, then create the board with letters

    // Fill the "board" with letters corresponding to "number_sudoku"
	for (row = 0; row < 9; row++) {
    	for (col = 0; col < 9; col++) {
			solved_board[row][col] = randomized_word[number_sudoku[row][col]-1];
			modified_board[row][col] = randomized_word[number_sudoku[row][col]-1];
		}
	}

	// Step 3: Implement a simple method similar to the "digging holes" algorithm found here: http://zhangroup.aporc.org/images/files/Paper_3485.pdf to create a sudoku puzzle

	// Clear the "hidden_letters" array first (set every value to 0)
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			hidden_letters[row][col] = 0;
		}
	}

	// While "positions_to_hide" is greater than 0, "dig" random letters out of the sudoku board 
	while (positions_to_hide) {
		random_row_number = rand() % 9; // generate a random row
		random_col_number = rand() % 9; // generate a random column
		// While the letter was already "dug out", generate a new column and row
		while (hidden_letters[random_row_number][random_col_number] == modified_board[random_row_number][random_col_number]) {
			random_row_number = rand() % 9;
			random_col_number = rand() % 9;
		}
		// Store the letter hidden to the "hidden_letters" array
		hidden_letters[random_row_number][random_col_number] = modified_board[random_row_number][random_col_number];
		// Set the position to a blank space in the "modified_board" so it displays that to the user
		modified_board[random_row_number][random_col_number] = ' ';
		positions_to_hide--; 
	}

}

/* 
Purpose: To get the user's choice for whether to (c) continue, (g) give up, (h) hint, or (q) quit the game.
Parameters: None
Returns: A valid user choice for whether to (c) continue, (g) give up, (h) hint, or (q) quit the game. The returned value will be a char.
Side Effects: 
*/
int get_choice() {

	// The user's choice
	char choice = 0;

	// Get the user’s choice for whether to continue, give up, or quit
	printf("\n\nEnter 'c' to continue, 'h' to get a hint, 'g' to give up, or 'q' to quit: ");
    scanf("%c", &choice);
	fgetc(stdin);

	// While the response is invalid, reprompt the user
	while ((choice != 'C') && (choice != 'c') && (choice != 'H') && (choice != 'h') && (choice != 'G') && (choice != 'g') && (choice != 'Q') && (choice != 'q')) {
		printf("Your choice of '%c' is an invalid choice. Please enter either 'c', 'h', 'g', or 'q': ", choice);
		scanf("%c", &choice);
		fgetc(stdin);
	}

	// Return the user's choice
	return choice;

}

/* 
Purpose: To get the user input for either a row or column number to insert a letter in.
Parameters: name - either 'row' or 'column'.
Returns: A valid user input for the row/column number (from 1 to 9).
Side Effects: None
*/
int get_row_or_col(char* row_or_col) {

	// The row/column number 
	int number = 0;

	// Prompt the user for the row/column number
	printf("\nPlease enter the the %s where you want to insert a letter at: ", row_or_col);
    scanf("%d", &number);
	fgetc(stdin);

	// While the input is invalid, reprompt the user
    while ((number > 9) || (number < 1)) {
        printf("Your input of '%d' is not within the range. Please specify a valid %s: ", number, row_or_col);
        scanf("%d", &number);
		fgetc(stdin);
    }

	// Return the row/column number
	return number;

}

/* 
Purpose: To check whether the row and column entered by the user is a valid square (there wasn't a letter there in the start).
Parameters: row_number - the row number.
			col_number - the column number.
			hidden_letters - the array that stores the hidden letters.
Returns: 1 (valid position) or 0 (invalid poisiton).
Side Effects: None
*/
int check_position(int row_number, int col_number, char hidden_letters[9][9]) {

	// Whether the position entered by the user is valid
	int valid = 0;

	// The user can only insert a letter at a position which was "hidden" in the "generate_board" function
	if (hidden_letters[row_number-1][col_number-1]) { // subtract "row_number" and "col_number" because computers start counting at 0
		valid = 1;
	}
	else {
		printf("\nYou can't insert a value at (row: %d, col: %d), as a letter has already been set by the computer.\n", row_number, col_number);
	}

	// Return whether the position is valid
	return valid;

}

/* 
Purpose: To get a valid letter from the user to insert at the desired position.
Parameters: word - the randomly generated word.
			row_number - the row number.
			col_number - the column number.
Returns: A valid letter entered by the user.
Side Effects: None
*/
char get_letter(char* word, int row_number, int col_number) {

	// Looping variable to use while going through the char array "word"
	int index = 0;
	// The letter to be inserted
	char letter = 0; 
	// Whether the letter is valid
	int invalid = 1;

	// Get a letter input to insert the the indicated position
	printf("\nPlease enter a letter to insert at position (row: %d, col: %d): ", row_number, col_number);
    scanf("%c", &letter);
	fgetc(stdin);

    // Check whether the letter is in the word that was generated or not
	for (index = 0; index < 9; index++) {
		// Acount for upper case letters as well
		if ((word[index] == letter) || (word[index] - 32 == letter)) { 
			invalid = 0;
			if (word[index] - 32 == letter) {
				letter += 32;
			}
		}
	}

	// While the letter is not in the word that was generated, reprompt the user
	while (invalid) {

		printf("Your input of '%c' is not a letter in \"%s\". Please enter a valid letter to insert: ", letter, word);
    	scanf("%c", &letter);
		fgetc(stdin);

		// Check whether the letter is in the word that was generated or not again
		for (index = 0; index < 9; index++) {
			// Acount for upper case letters as well
			if ((word[index] == letter) || (word[index] - 32 == letter)) { 
				invalid = 0;
				if (word[index] - 32 == letter) {
					letter += 32;
				}
			}
		}
		
	}

	// Return the letter entered by the user
    return letter;

}

/* 
Purpose: To update the board each time a new letter is inserted.
Parameters: board - the board to be updated (not the original board).
			row_number - the row number.
			col_number - the column number.
			letter - the letter to insert.
Returns: None
Side Effects: None
*/
void update_board(char board[9][9], int row_number, int col_number, char letter) {
	// Insert the desired value at the desired position
	board[row_number-1][col_number-1] = letter; // subtract "row_number" and "col_number" because computers start counting at 0
}

/* 
Purpose: To provide a hint to the user by making a move for them.
Parameters: modified_board - the board that is being modified by the user.
			solved_board - the board generated at the beginning that is solved.
			hints - the number of hints remaining for the user to use.
Returns: None
Side Effects: None
*/
void give_hint(char modified_board[9][9], char solved_board[9][9], int hints) {

	// Looping variables to use while going through a 2D array
	int row = 0; 
	int col = 0;
	// Variables to store the row and column numbers of the hint 
	int row_number = -1;
	int col_number = -1;
	
	// Go through the sudoku and reveal the first unknown letter
	for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
			// Find the first place where there is an empty spot
			if (modified_board[row][col] == ' ') {
				row_number = row;
				col_number = col;
			}
		}
	}

	// If the "row_number" and "col_number" are still the same, that means there are no more empty spots
	// This means the user filled out the entire board but the board isn't solved properly (there are repeating letters in rows, columns, or 3x3 grids)
	if ((row_number == -1) && (col_number == -1)) {
		// In this case, inform the user that the board isn't solved properly
		printf("\n\nCheck your board again, because there are either repeating letters in a row, a column, or a 3x3 grid.");
	}

	else {
		// Update the board to show the hint
		update_board(modified_board, row_number+1, col_number+1, solved_board[row_number][col_number]);
		printf("\n\nHere is your hint %d:", 10-hints+1);
	}

}

/* 
Purpose: To show the user what the sudoku board looks like.
Parameters: board - the sudoku board to be displayed.
Returns: None
Side Effects: None
*/
void display_board(char board[9][9]) {

	// Looping variables to use while going through a 2D array
	int row = 0; 
	int col = 0;

	printf("\n\n");
    printf(" 0 | 1  2  3 | 4  5  6 | 7  8  9 | col\n");
    printf(" ---------------------------------\n");

	// Go through each row and columnn to print out the values
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (col == 0) {
                printf(" %d |", row + 1);
			}	
            else if (col % 3 == 0) {
                printf("|");
			}
            printf(" %c ", board[row][col]);
            if (col == 8) {
                printf("|");
			}
        }
        printf("\n");
        if ((row + 1) % 3 == 0) {
            printf(" ---------------------------------\n");
		}
    }

	printf("row\n");

}

/* 
Purpose: To check each 3x3 grid in the board (there are 9 in total) and see whether they contain unique letters.
Parameters: board - the board that is being updated.
			word - the randomly generated word.
			ascii_sum - the sum of all the ascii values of the letters in "word".
			row_start - start index of the row.
			col_start - start index of the column.
Returns: 1 (the 3x3 grids are all solved) or 0 (not all of the 3x3 grids are solved).
Side Effects: 
*/
int check_3x3_grid(char board[9][9], int ascii_sum, int row_start, int col_start) {

	// Looping variables to use while going through a 2D array
	int row = 0; 
	int col = 0;
	// The sum of the 3x3 grid
	int sum = 0;

	// Go through the 3x3 grid and get the sum of the ascii values of the letters
	for (row = row_start; row < row_start+3; row++) {
		for (col = col_start; col < col_start+3; col++) {
			sum += board[row][col];
		}	
	}

	// If the "sum" isn't equal to the "ascii_sum", then the sudoku board isn't solved
	if (sum != ascii_sum) {
		return 0;
	}

	// If the program reaches here, that means all 3x3 grids of the sudoku board are perfectly solved
	return 1;

}

/* 
Purpose: To check whether the board is solved.
Parameters: board - the board that is being updated. 
			word - the randomly generated word.
Returns: 0 (if the board isn't solved) or 1 (if the board is solved).
Side Effects: None
*/
int check_board(char board[9][9], char* word) {

	// Looping variables to use while going through a 2D array
	int row = 0; 
	int col = 0;
	// Lopping varaible to use while going through the char array "word"
	int index = 0;
	// The sum of the ascii values of each of the letters in the "word"
	int ascii_sum = 0;
	// The sum of the ascii values of each of the letters in a row or in a column
	int sum = 0;

	/* If the sum of all rows, columns, and 3x3 squares is equal to the sums of the ASCII values of the letters in "word", the board 
	is solved, as it contains all unique letters. We first assume the board is solved, so we can prove by contradiction */

	// Find the sum of the ASCII values of the letters in "word"
	for (index = 0; index < 9; index++) {
		ascii_sum += (int) word[index];
	}

	// Go through each row and see if they sum up to "ascii_sum"
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			sum += board[row][col];
		}
		if (sum != ascii_sum) {
			return 0;
		}
		else {
			sum = 0; // reset the sum to use for later;
		}
	}

	// Go through each column and see if they sum up to "ascii_sum"
	for (col = 0; col < 9; col++) {
		for (row = 0; row < 9; row++) {
			sum += board[col][row];
		}
		if (sum != ascii_sum) {
			return 0;
		}
		else {
			sum = 0; // reset the sum to use for later;
		}
	}

	// Go through each of the 9 3x3 grids and determine whether they are all solved
	if (!check_3x3_grid(board, ascii_sum, 0, 0) 
	|| !check_3x3_grid(board, ascii_sum, 0, 3) 
	|| !check_3x3_grid(board, ascii_sum, 0, 6) 
	|| !check_3x3_grid(board, ascii_sum, 3, 0) 
	|| !check_3x3_grid(board, ascii_sum, 3, 3) 
	|| !check_3x3_grid(board, ascii_sum, 3, 6) 
	|| !check_3x3_grid(board, ascii_sum, 6, 0) 
	|| !check_3x3_grid(board, ascii_sum, 6, 3) 
	|| !check_3x3_grid(board, ascii_sum, 6, 6)) {
		return 0;
	}

	// If the program reaches here, that means the sudoku board is perfectly solved
	return 1;

}

int main() {

	// Set the seed for the rand() function
	srand(time(NULL));

	// "Boolean" variables to determine when a game should be stopped or when the program should quit
	int game = 1;
	int keep_playing = 1;
	// The number of games played
	int game_number = 0;
	// The number of times the user solved a sudoku
	int successes = 0;
	int fails = 0;
	// The randomly generated word from a list of over 1000 words
	char *word;
	// The board generated by the "generate_board()" function before letters are hidden
	char solved_board[9][9];
	// This is the board that gets modified until the user gives up or solves it
	char modified_board[9][9];
	// This array stores all the hidden letters
	char hidden_letters[9][9]; 
	// The user's choice for whether to continue solving a puzzle, give up, or quit the game
	char choice = 0;
	// The row and column numbers of a position of a letter on the sudoku board
	int col_number; 
	int row_number; 
	// The letter to be inserted
	char letter = 0; 
	// There can only be a maximum of 10 hints 
	int hints = 10;

	// Print out the instructions
	print_instructions();

	// While "keep_playing" is equal to 1 (true), the overall game will continue
	while (keep_playing) {

		printf("\n--------------------------------------------------------------------------------");

		// Print out the game number
		game_number++;
		printf("\n\n{Game %d}", game_number);

		// Get a random word from the list, store it in "word", and inform the user what the word is
		word = generate_word();
		printf("\n\nThe randomly generated word is: %s", word);

		// Display the sudoku board for the user to see
		generate_board(solved_board, modified_board, hidden_letters, word);

		// Set "game" equal to 1 (true) first, and when the user gives up or quits, set it to 0 (false)
        game = 1;

		// Display the board generated
		display_board(modified_board);
		
		// While "keep_playing" is equal to 1 (true), the specific game will continue
		while (game) {

			// Get the user's choice for whether to continue playing, get a hint, give up, or quit the game
			choice = get_choice();

			// If the user chooses to quit the game
			if ((choice == 'q') || (choice == 'Q')) {
				printf("\n\nYou chose to quit the game.\n");
				keep_playing = 0; // the user doesn't want to keep playing the overall game
				game = 0; // the user doesn't want to keep trying
			}

			// If the user chooses to give up
			else if ((choice == 'g') || (choice == 'G')) {
				// Show the solution for the board 
				printf("\n\nHere is the solution:");
				display_board(solved_board);
				game = 0; // the user doesn't want to keep trying
				fails++; // the user was unsuccessful
				hints = 10; // reset the hints 
			}

			// If the user chooses to get a hint
			else if ((choice == 'h') || (choice == 'H')) {
				// The user still has hints to use
				if (hints > 0) {
					// Give a hint to the user10-
					give_hint(modified_board, solved_board, hints);
					hints--; 
				}
				// The user has no more hints to use
				else {
					printf("\n\nYou have used all 10 hints already.");
				}
			}

			// If the user chooses to continue
			else {
				// Get the position to insert a letter in 
				row_number = get_row_or_col("row");
				col_number = get_row_or_col("column");
				// Check whether the position is valid
				while (!check_position(row_number, col_number, hidden_letters)) {
					row_number = get_row_or_col("row");
					col_number = get_row_or_col("column");
				}
				// Get the letter 
				letter = get_letter(word, row_number, col_number);
				// Update the board
				update_board(modified_board, row_number, col_number, letter);
			}

			// Check if the board is solved
			if (check_board(modified_board, word)) {
				printf("\n\nCongratulations! You solved the sudoku puzzle with %d hints!", 10-hints);
				display_board(solved_board);
				game = 0; // the game is finished 
				successes++; // the user was successful
				hints = 10; // reset the hints 
			}

			// Print out the word and display the board if "game" is still equal to 1 (true)
			if (game) {
				printf("\n\n[Word: %s]", word);
				display_board(modified_board);
			}

		}

	}

	// Display simple statistics and print out a thank you message
	printf("\n--------------------------------------------------------------------------------");
	printf("\n\nThank you for playing this Word Sudoku game!");
	printf("\n\nYou successfully solved %d puzzle(s) and failed to solve %d puzzle(s).", successes, fails);
	printf("\n\n--------------------------------------------------------------------------------\n\n");

    return 0;

}
