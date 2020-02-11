# DMCP SDK

## This repo contains the sources for basic SDK for the DM Calculator Platform (DMCP) along with the simple 'Hello World!' demo project

- There is DMCP interface doc in progress see [DMCP IFC doc](http://www.swissmicros.com/dmcp/doc/DMCP-ifc-html/) (or
you can download HTML zip file from [doc directory](http://www.swissmicros.com/dmcp/doc/)).


DMCP SDK sources are in the dmpc/ directory, if you want to upgrade your own program to current
DMCP interface version you should copy the dmcp/ directory to your project.

README file contains basic instructions how to prepare your own building environment as well as the
instructions how to turn this basic SDK project to your own one.

You can look at SDKdemo project (simple scientific RPN calculator) for more advanced project with
keyboard handling, more sophisticated LCD printing, power management, build with Intel® Decimal
Floating-Point Math Library, user defined menus and more.

For ultimate project which uses other aspect of the DMCP system (like system timers, bitmap printing
to LCD or printing to IR printer) look at sources of the DM42PGM project.

At this time the only source of information about the use of DMCP system interface is based on
the source code of DMCP programs.

## The SDK and related material is released as “NOMAS”  (NOt MAnufacturer Supported). 

1. Info is released to assist customers using, exploring and extending the product

1. Do NOT contact the manufacturer with questions, seeking support, etc. regarding NOMAS material as no support is implied or committed-to by the Manufacturer

1. The Manufacturer may reply and/or update materials if and when needed solely at their discretion

