import requests
from bs4 import BeautifulSoup
from collections import Counter

if __name__ == '__main__':
    url = "https://www.tandfonline.com/doi/full/10.1080/02286203.2019.1615261?src="
    r = requests.get(url) 
    soup = BeautifulSoup(r.text, "html.parser")  

    tags = [tag.name for tag in soup.find_all()] 
    counter = Counter(tags) 

    for tag in sorted(set(tags)): 
        print(tag, counter[tag])