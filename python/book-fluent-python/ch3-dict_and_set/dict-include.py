DIAL_CODES = [(86, "China"), (91, "India"), (7, "Russia"), (55, "Brazil")]
print(type(DIAL_CODES))
# >>> <class 'list'>
print(DIAL_CODES)
# >>> [(86, 'China'), (91, 'India'), (7, 'Russia'), (55, 'Brazil')]

# (1)
country_codes = {country: code for code, country in DIAL_CODES}
print(country_codes)
# >>> {'China': 86, 'India': 91, 'Russia': 7, 'Brazil': 55}

# (2)
new_countries = {
    code: country.upper() for country, code in country_codes.items() if code < 80
}
print(new_countries)
# >>> {7: 'RUSSIA', 55: 'BRAZIL'} 
