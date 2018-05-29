import glob
import os
import subprocess

def invoke(*args):
	subprocess.check_call(args)

invoke('git', 'submodule', 'update', '--init', '--recursive')

try: os.mkdir('built')
except: pass
os.chdir('built')
invoke('cmake', '..')
invoke('cmake', '--build', '.')

invoke(glob.glob('./joyrider*')[0])
