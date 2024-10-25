#!/usr/bin/env bash
PROJECT="chunk-legion:5000/banshee-ubuntu2204"
tag='latest'
resolvectl flush-caches
if [ "$1" = "-c" ]
then
	docker builder prune
	docker build --no-cache -t $PROJECT:$tag .
else
	docker build -t $PROJECT:$tag .
fi
