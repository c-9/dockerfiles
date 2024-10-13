#!/usr/bin/env bash
PROJECT="chunk-legion:5000/zsim-ubuntu1804"
tag='latest'
sudo resolvectl flush-caches
if [ "$1" = "-c" ]
then
	docker builder prune
	docker build --no-cache -t $PROJECT:$tag .
else
	docker build -t $PROJECT:$tag .
fi
