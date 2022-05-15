import os
from invoke import task

@task(default=True)
def package(c):
    n = os.path.basename(os.getcwd())
    c.run("mkdir -p order/", warn=True)
    c.run("rm -rf order/*", warn=True)
    c.run(f"cp out/{n}-F_Cu.gbr order/{n}.GTL")
    c.run(f"cp out/{n}-B_Cu.gbr order/{n}.GBL")
    c.run(f"cp out/{n}-F_Mask.gbr order/{n}.GTS")
    c.run(f"cp out/{n}-B_Mask.gbr order/{n}.GBS")
    c.run(f"cp out/{n}-F_Silkscreen.gbr order/{n}.GTO")
    c.run(f"cp out/{n}-B_Silkscreen.gbr order/{n}.GBO")
    c.run(f"cp out/{n}-PTH.drl order/{n}.TXT")
    c.run(f"cp out/{n}-NPTH.drl order/{n}-NPTH.TXT")
    c.run(f"cp out/{n}-Edge_Cuts.gbr order/{n}.GML")
    with c.cd("order"):
        c.run(f"zip _.zip {n}*")
        c.run(f"mv _.zip {n}.zip")

@task()
def revert(c):
    n = os.path.basename(os.getcwd())
    c.run(f"cp order/{n}.GTL revert/{n}-F_Cu.gbr ")
    c.run(f"cp order/{n}.GBL revert/{n}-B_Cu.gbr ")
    c.run(f"cp order/{n}.GTS revert/{n}-F_Mask.gbr ")
    c.run(f"cp order/{n}.GBS revert/{n}-B_Mask.gbr ")
    c.run(f"cp order/{n}.GTO revert/{n}-F_SilkS.gbr ")
    c.run(f"cp order/{n}.GBO revert/{n}-B_SilkS.gbr ")
    c.run(f"cp order/{n}.TXT revert/{n}-PTH.drl ")
    c.run(f"cp order/{n}-NPTH.TXT revert/{n}-NPTH.drl ")
    c.run(f"cp order/{n}.GML out/{n}-revert.gbr ")

@task
def clean(c):
    c.run("rm -rf out/*")
    c.run("rm -rf order/*")

