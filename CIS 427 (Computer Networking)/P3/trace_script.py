import os
import sys
import inspect

JAPAN = "cmoa.jp"
AUSTRALIA = "violetcrumble.com"
SOUTH_AFRICA = "dstv.com"
NORWAY = "dhis2.org"
GERMNAY = "German-dating-sites.de"
UK = "185.220.162.23"
RUSSIA = "77.88.55.70"
USA = "172.217.4.206"
BRAZIL = "globo.com"
CANADA = "starlink.com"


SITES = [JAPAN,AUSTRALIA,SOUTH_AFRICA,NORWAY,GERMNAY,UK,RUSSIA,USA,BRAZIL,CANADA]


def retrieve_name(var):
    callers_local_vars = inspect.currentframe().f_back.f_locals.items()
    return [var_name for var_name, var_val in callers_local_vars if var_val is var]

for site in SITES:
    filename = site.split(".")
    country = retrieve_name(site)
    os.system(f"tracert {site} >{sys.argv[1]}-tracert-{filename[0]}({country[0]}).txt")
    print(f"{country[0]} Ping Done")



print("\nSuccess. All sites pinged and traced.")
