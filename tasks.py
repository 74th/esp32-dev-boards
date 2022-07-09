import os
from invoke import task

@task(default=True)
def package(c):
    n = os.path.basename(os.getcwd())
    with c.cd("out"):
        c.run(f"rm {n}.zip", warn=True)
        c.run(f"zip _.zip {n}*")
        c.run(f"mv _.zip {n}.zip")

@task
def clean(c):
    c.run("rm -rf out/*")
    c.run("rm -rf order/*")

