basic_words = {"water": "sul", "food": "nan", "home": "kun", "sun": "kula", "moon": "luna", "love": "tala", "like": "kela", "not": "nat", "person": "ama", "animal": "nami", "thing": "suli", "cat": "catin", "dog": "dogin", "person": "pere", 'the': 'ka', 'and': 'hi', 'of': 'lo', 'to': 'to', 'a': 'sa', 'in': 'na', 'that': 'tas', 'is': 'kalet', 'for': 'ko', 'it': 'ti', 'with': 'solakunom', 'you': 'nam', 'be': 'ta', 'on': 'nalet', 'not': 'ni', 'are': 'talet', 'this': 'tis', 'or': 'ro', 'they': 'totom', 'from': 'so', 'at': 'at', 'by': 'by', 'but': 'hut', 'we': 'totim', 'an': 'sa', 'he': 'het', 'she': 'set', 'if': 'if', 'do': 'do', 'their': 'totomlet', 'up': 'up', 'has': 'halet', 'will': 'will', 'there': 'theres', 'about': 'abot', 'out': 'out', 'so': 'sot', 'just': 'jus', 'more': 'mor', 'when': 'when', 'also': 'also', 'time': 'tim', 'could': 'could', 'no': 'no', 'only': 'only', 'new': 'new', 'these': 'thiset', 'two': 'twot', 'know': 'know', 'other': 'other', 'then': 'then', 'him': 'hem', 'her': 'her', 'into': 'into', 'than': 'than', 'now': 'now', 'some': 'som', 'me': 'me', 'my': 'my', 'such': 'sach', 'like': 'li', 'our': 'our', 'over': 'over', 'man': 'po', 'even': 'even', 'most': 'most', 'made': 'made', 'after': 'after', 'also': 'also', 'many': 'many', 'must': 'must', 'through': 'through', 'back': 'back', 'years': 'yearsom', 'where': 'where', 'much': 'much', 'your': 'yor', 'before': 'befor', 'us': 'us', 'two': 'twot', 'own': 'own', 'those': 'thoset', 'down': 'down', 'never': 'never', 'without': 'without', 'made': 'made', 'good': 'good', 'being': 'bein', 'day': 'day', 'get': 'get', 'come': 'come', 'see': 'see', 'could': 'could', 'go': 'go', 'work': 'work', 'way': 'way', 'make': 'make', 'want': 'want', 'look': 'look', 'use': 'use', 'find': 'find', 'and': 'an', 'animal': 'do', 'baby': 'fasol', 'love': 'la', 'mother': 'kam', 'cat': 'kat', 'with': 'ke', 'home': 'ko', 'is going': 'kulanit', 'with joy': 'lalunom', 'like': 'li', 'inside': 'lin', "don't worry": 'lunanam', 'moon': 'me', 'father': 'nan', 'you': 'nam', 'not': 'ni', 'now': 'no', 'family': 'pokam', 'person': 'po', 'big plan': 'rasol', 'plan': 'sasol', 'thing': 'si', 'with some issues': 'solakunom', 'sun': 'so', 'day': 'som', 'fatherland': 'sukam', 'time': 'ti', 'food': 'to', 'night': 'tum', 'home land': 'wakam', 'water': 'wa', 'will': 'wi', 'place': 'yakam', 'year': 'yo', 'sky': 'zam' }

# Define the translation function
def english_to_that(sentence):
    translated_words = []
    for word in sentence.split():
        if word in basic_words:
            translated_words.append(basic_words[word])
    return ' '.join(translated_words)

def that_to_english(sentence):
    reversed_dict = {v:k for k, v in basic_words.items()}
    translated_words = []
    for word in sentence.split():
        if word in reversed_dict:
            translated_words.append(reversed_dict[word])
    return ' '.join(translated_words)



sentence = "I love my home and my family"
that_sentence = english_to_that(sentence)
print(that_sentence)

english_sentence = that_to_english(that_sentence)
print(english_sentence)