class Set:
    def __init__(self, k):
        self.blocks = []
        self.k = k
        self.usage_queue = [] # indices of blocks in list that have been used

    def is_in_cache(self, block_id):
        return block_id in self.blocks

    def insert_block(self, block_id):
        # replace
        if len(self.blocks) == self.k:
            LRU = self.usage_queue[0]
            self.blocks[LRU] = block_id
            self.usage_queue.pop(0)
        # insert
        else:
            self.blocks.append(block_id)

    def update_usage_queue(self, block_id):
        block_index = self.blocks.index(block_id)

        if block_index in self.usage_queue:
            self.usage_queue.remove(block_index)

        self.usage_queue.append(block_index)

def main():
    miss_counter = 0

    cache_size = 1024
    block_size = 128
    k = 1
    memory_references = 48

    num_blocks_in_cache = int(cache_size / block_size)
    num_sets = int(num_blocks_in_cache / k)

    block_id_reading_list = [1, 2, 3, 5, 6, 2, 3, 4, 9, 10, 11, 6, 3, 6, 1, 7, 8, 4, 5, 9, 11, 1, 2, 4, 5, 12, 13, 14, 15, 13, 14]

    sets = [Set(k) for i in range(num_sets)]

    for block_id in block_id_reading_list:
        set_id = block_id % num_sets
        set = sets[set_id]

        if not set.is_in_cache(block_id):
            set.insert_block(block_id)
            miss_counter += 1

        set.update_usage_queue(block_id)

        print(set_id, set.blocks, set.usage_queue)

    print('miss counter:', miss_counter)

    for set in sets:
        print(set.blocks)

    blocks_read = len(block_id_reading_list)
    num_memory_references = blocks_read * memory_references

    print('blocks read:', blocks_read)
    print('num memory references:', num_memory_references)
    print('cache hit rate:', 1 - miss_counter / num_memory_references)

if __name__ == "__main__":
    main()
