# -*- coding: utf-8 -*-
#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      item4
#
# Created:     09-06-2013
# Copyright:   (c) item4 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------
from sqlalchemy import create_engine
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String
from sqlalchemy.orm import sessionmaker
from sqlalchemy import ForeignKey
from sqlalchemy.orm import relationship, backref

Base = declarative_base()



def main():
    engine = create_engine('mysql+oursql://item4:iitnenmo4cent@snoin.com/item4', echo=True)
    print engine.execute("show tables").scalar()

if __name__ == '__main__':
    main()
